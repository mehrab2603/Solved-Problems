#include <iostream>
#include <cstdio>

using namespace std;
double df(double, double, double, double);

int main()
{
    while(1)
    {
        double n, a1, x1, x2, x3, x4, y1, y2, y3, y4, m = 0;
        scanf("%lf %lf", &n, &a1);
        if(n == 0) break;
        x1 = 0, y1 = 0;
        x2 = a1, y2 = 0;
        x3 = a1, y3 = a1;
        x4 = 0, y4 = a1;
        long long k = n;
        while(k--)
        {
            double a, b;
            scanf("%lf %lf", &a, &b);
            double d1 = df(x1, y1, a, b);
            double d2 = df(x2, y2, a, b);
            double d3 = df(x3, y3, a, b);
            double d4 = df(x4, y4, a, b);
            if(d1 <= a1 * a1)
                if(d2 <= a1 * a1)
                    if(d3 <= a1 * a1)
                        if(d4 <= a1 * a1)
                            m++;
        }
        printf("%.5lf\n", m*a1*a1/n);
    }
        return 0;
}

 double df(double x1, double y1, double x2, double y2)
 {
     return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
 }

