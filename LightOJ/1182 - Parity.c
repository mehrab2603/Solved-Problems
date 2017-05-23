#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,i,caseno=0;
    scanf("%d", &t);
    while(t--)
    {
        int countno=0;
        scanf("%d", &n);
        for(i=0;i<32;i++)
        {
            if(n&(1<<i)) countno++;
        }
        if(countno%2==0) printf("Case %d: even\n",++caseno);
        else printf("Case %d: odd\n",++caseno);
    }
    return 0;
}
