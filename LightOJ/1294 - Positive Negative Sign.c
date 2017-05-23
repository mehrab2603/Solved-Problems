#include<stdio.h>
int main()
{
    int i,t;
    long long n,m;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld %lld",&n,&m);
        printf("Case %d: %lld\n",i,(n*m)/2);
    }
    return 0;
}
