#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-10;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        double a, b;
        scanf("%lf : %lf", &a, &b);


        double sq = sqrt(a * a + b * b);
        double theta = atan(b / a);

        double lo = 0, hi = INT_MAX;
        while(hi - lo > eps) {
            double mid = (hi + lo) / 2;

            double perimeter = 2 * mid * (a + sq * theta);

            if(perimeter > 400) hi = mid;
            else if(perimeter < 400) lo = mid;
            else break;
        }
        printf("Case %d: %.8lf %.8lf\n", ++caseno,  a * lo, b * lo);
    }
    return 0;
}
