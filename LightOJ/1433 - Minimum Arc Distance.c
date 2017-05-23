#include <stdio.h>
#include <math.h>

int main()
{
    int t, ox,oy,ax,ay,bx,by, caseno=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d", &ox,&oy,&ax,&ay,&bx,&by);
        double b=sqrt(pow(ox-ax,2)+pow(oy-ay,2));
        double a=sqrt(pow(ox-bx,2)+pow(oy-by,2));
        double o=sqrt(pow(ax-bx,2)+pow(ay-by,2));
        double theta=acos((a*a+b*b-o*o)/(2*a*b));
        printf("Case %d: %lf\n",++caseno,a*theta);
    }
    return 0;
}
