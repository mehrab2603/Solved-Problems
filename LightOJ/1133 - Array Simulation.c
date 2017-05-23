#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,m,n,caseno=0;
    scanf("%d", &t);
    while(t--)
    {
        int i,a[99];
        char ch;
        scanf("%d %d", &n,&m);
        for(i=0;i<n;i++)scanf("%d", &a[i]);
        while(m--)
        {
            scanf(" %c", &ch);
            if(ch=='S')
            {
                int x;
                scanf("%d", &x);
                for(i=0;i<=n-1;i++) a[i]+=x;
            }
            else if(ch=='M')
            {
                int x;
                scanf("%d", &x);
                for(i=0;i<=n-1;i++) a[i]*=x;
            }
            else if(ch=='D')
            {
                int x;
                scanf("%d", &x);
                for(i=0;i<=n-1;i++) a[i]/=x;
            }
            else if(ch=='R')
            {
                int x,j;
                for(i=0,j=n-1;j>i;i++,j--)
                {
                    x=a[i];
                    a[i]=a[j];
                    a[j]=x;
                }
            }
            else if(ch=='P')
            {
                int x,y,z;
                scanf("%d %d", &x,&y);
                z=a[x];
                a[x]=a[y];
                a[y]=z;

            }
        }
        printf("Case %d:\n",++caseno);
        for(i=0;i<n-1;i++) printf("%d ", a[i]);
        printf("%d\n", a[i]);

    }
    return 0;
}
