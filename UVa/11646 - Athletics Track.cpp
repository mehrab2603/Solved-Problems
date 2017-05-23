#include<bits/stdc++.h>
#define PI 2 * acos(0.0)
#define eps 1e-10

using namespace std;

int length, width;

double func(double);

int main() {
    int caseno = 0;
    while(scanf("%d : %d", &length, &width) != EOF) {
        double lo = 0, hi = 10000.0, mid;
        while(hi - lo > eps) {
            mid = lo + (hi - lo) / 2;
            double key = func(mid);
            if(key > 400) hi = mid;
            else lo = mid;
        }
        printf("Case %d: %lf %lf\n", ++caseno, length * lo, width * lo);
    }
    return 0;
}

double func(double q) {
    double len = length * q, wid = width * q;
    double diagonal = sqrt(len * len + wid * wid);
    double c = diagonal / 2.0, a = c, b = wid;
    double B = acos((c * c + a * a - b * b) / (2.0 * c * a)) * (180 / (PI));
    return 2.0 * len + 2.0 * (((PI * c) / 180.0) * B);
}
