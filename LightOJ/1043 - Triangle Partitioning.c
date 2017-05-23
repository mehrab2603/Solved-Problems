#include <stdio.h>
#include <math.h>

int main()
{
    int t, caseno=0;
    double ab,ac,bc,rat;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf", &ab,&ac,&bc,&rat);
        printf("Case %d: %lf\n",++caseno,sqrt(rat/(rat+1))*ab);
    }
    return 0;
}
