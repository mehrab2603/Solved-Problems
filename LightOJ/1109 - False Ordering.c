#include <stdio.h>
#include <stdlib.h>
int divno(int);

int main()
{
    int t,n,j,num[1000];
    scanf("%d", &t);
    for(j=1;j<1001;j++) num[j]=divno(j);
    while(t--)
    {

    }
    return 0;
}

int divno(int n)
{
    int i,divcount=0;
    if(n==1) return 1;
    for(i=1;i<=n/2;i++)
    {
        if(n%i==0) divcount++;
    }
    return divcount+1;
}
