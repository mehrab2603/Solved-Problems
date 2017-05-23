#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,r1,c1,r2,c2,caseno=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d", &r1,&c1,&r2,&c2);
        if(r1==r2)
        {
            if((c1-c2)%2==0) printf("Case %d: 2\n",++caseno);
            else if((c1-c2)%2!=0) printf("Case %d: impossible\n",++caseno);
        }
        else if(c1==c2)
        {
            if((r1-r2)%2==0) printf("Case %d: 2\n",++caseno);
            else if((r1-r2)%2!=0) printf("Case %d: impossible\n",++caseno);
        }
        else if(((r1-r2)%2==0&&(c1-c2)%2==0)||((r1-r2)%2!=0&&(c1-c2)%2!=0))
        {
            if((r1-r2)==(c1-c2)||(r1-r2)==(-1)*(c1-c2)) printf("Case %d: 1\n",++caseno);
            else printf("Case %d: 2\n",++caseno);
        }
        else if(((r1-r2)%2==0&&(c1-c2)%2!=0)||((r1-r2)%2!=0&&(c1-c2)%2==0))
        {
            printf("Case %d: impossible\n",++caseno);

        }

    }
    return 0;
}
