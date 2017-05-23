#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, caseno=0;
    double v1,v2,v3,a1,a2,t1,t2,t3;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf %lf", &v1,&v2,&v3,&a1,&a2);
        t1=v1/a1;
        t2=v2/a2;
        if(t1>t2) t3=t1;
        else t3=t2;
        printf("Case %d: %lf %lf\n", ++caseno,((v1/2)*t1)+((v2/2)*t2),t3*v3);
    }
    return 0;
}
