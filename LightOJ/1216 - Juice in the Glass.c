#include <stdio.h>
#include <math.h>
#define pi 2*acos(0.0)

int main()
{
    double t,r1,r2,h,p, caseno=0;
    scanf("%lf", &t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf", &r1,&r2,&h,&p);
        double r3=p*(r1-r2)*(1/h)+r2;
        printf("Case %g: %lf\n",++caseno, ((pi*p)/3.0)*(r3*r3+r3*r2+r2*r2));

    }
    return 0;
}
