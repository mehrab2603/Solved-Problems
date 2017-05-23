#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,caseno=0;
    long n1,n2,n3;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%ld %ld %ld", &n1,&n2,&n3);
        if(n1>n2 && n1>n3)
        {
            if(n1*n1==n2*n2+n3*n3) printf("Case %d: yes\n",++caseno);
            else printf("Case %d: no\n",++caseno);
        }
        else if(n2>n1 && n2>n3)
        {
            if(n2*n2==n1*n1+n3*n3) printf("Case %d: yes\n",++caseno);
            else printf("Case %d: no\n",++caseno);
        }
        else
        {
            if(n3*n3==n2*n2+n1*n1) printf("Case %d: yes\n",++caseno);
            else printf("Case %d: no\n",++caseno);
        }
    }
    return 0;
}
