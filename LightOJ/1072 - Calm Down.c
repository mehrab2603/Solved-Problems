#include <stdio.h>
#include <math.h>

int main()
{
    int t, caseno=0,n;
    double R;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf %d", &R, &n);
        long double theta = 3.14159265358979323846264338327950288419716939937510/n;

        printf("Case %d: %lf\n", ++caseno, (R*sin(theta))/(1+sin(theta)));
    }
    return 0;
}
