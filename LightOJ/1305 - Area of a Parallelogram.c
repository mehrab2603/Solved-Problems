#include <stdio.h>
#include <math.h>

int main()
{
    int t,ax,ay,bx,by,cx,cy,dx,dy,caseno=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d", &ax,&ay,&bx,&by,&cx,&cy);
        dy=cy-(by-ay);
        dx=cx-(bx-ax);
        int area=0.5*((ax-cx)*(by-dy)-(bx-dx)*(ay-cy));
        if(area<0) area*=-1;
        printf("Case %d: %d %d %d\n",++caseno,dx,dy,area);
    }
    return 0;
}
