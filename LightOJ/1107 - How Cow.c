#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,m,x,y,xdown,ydown,xup,yup,caseno=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d", &xdown,&ydown,&xup,&yup);
        scanf("%d", &m);
        printf("Case %d:\n", ++caseno);
        while(m--)
        {
            scanf("%d %d", &x, &y);
            if((x>xdown && x<xup)&&(y>ydown&&y<yup)) printf("Yes\n");
            else printf("No\n");
        }

    }
    return 0;
}
