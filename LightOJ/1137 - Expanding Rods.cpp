#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-10;

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        double l, n, c;
        scanf("%lf %lf %lf", &l, &n, &c);
        double l2 = (1 + n * c) * l;
        if(n == 0 || c == 0) {
            printf("Case %d: %.8lf\n", ++caseno, 0);
            continue;
        }

        double lo = 0, hi = l / 2;
        while(hi - lo > eps) {
            double mid = (lo + hi) / 2;
            double l3 = ((l * l) / (8.0 * mid) + mid / 2.0) * 2 * atan(l / (2 * ((l * l) / (8.0 * mid) - mid / 2.0)));
            if(l3 < l2) lo = mid;
            else if(l3 > l2) hi = mid;
        }
        printf("Case %d: %.8lf\n", ++caseno, lo);
    }
    return 0;
}
