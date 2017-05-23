#include <bits/stdc++.h>

using namespace std;

const int eps = 1e-9;

int main()
{
    int m;
    scanf("%d", &m);
    while(m--)
    {
        int n, k;
        double p, x;
        scanf("%d %lf %d", &n, &p, &k);
        if(p == 0) {printf("0.0000\n"); continue;}
        x = 1 - p + eps;
        double ans = (pow(x, k - 1) + eps) * p * (1 / (1 - pow(x, n) + eps) + eps) + eps;
        printf("%.4lf\n", ans);
    }
    return 0;
}
