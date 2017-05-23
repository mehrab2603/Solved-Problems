#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-10

using namespace std;
double calC(double, double, double);

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        double x, y, c;
        scanf("%lf %lf %lf", &x, &y, &c);
        double low = 0, high = min(x, y);
        double mid;
        while(high - low > eps)
        {
            mid = (low + high) / 2;
            double key = calC(mid, x, y);
            if(key > c) low = mid;
            else high = mid;
        }
        printf("Case %d: %lf\n", ++caseno, mid);
    }
    return 0;
}

double calC(double AB, double BC, double AF)
{
    double DE, AC, BF;
    AC = sqrt(BC*BC - AB*AB);
    BF = sqrt(AF*AF - AB*AB);
    DE = 1 / ((1 / AC) + (1 / BF));
    return DE;
}

