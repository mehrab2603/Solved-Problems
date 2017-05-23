#include <stdio.h>
#include <stdlib.h>
long lastfact(long ,long *);
int main()
{
    int t, caseno=0;
    scanf("%d", &t);
    while(t--)
    {
        long n,x,i=0,sum=1, a[100]={};
        scanf("%ld", &n);

        for(x=lastfact(n,&sum);n>=0;x=lastfact(n,&sum))
        {
            if(i>0 && (a[i-1]==x))
            {
                if(x>2 || x==0)
                {
                    printf("Case %d: impossible\n", ++caseno);
                    break;
                }
                else if(x==2 && n>2)
                {
                    printf("Case %d: impossible\n", ++caseno);
                    break;
                }
                else if(x==2 && n==2){a[i++]=1;a[i]=0;goto endpoint;}
                else if(x==1 && n==1){a[i]=0;goto endpoint;}

            }
            if(n==sum)
            {
                a[i]=x;
    endpoint:   printf("Case %d: ",++caseno);
                for(;i>0;i--) printf("%ld!+",a[i]);
                printf("%ld!\n",a[0]);
                break;
            }
            a[i++]=x;
            n=n-sum;
            sum=1;
        }
    }
    return 0;
}

long lastfact(long n, long *sum)
{
    if(n==0) return 0;
    int i=1;
    while(*sum<=n)
    {
        *sum=*sum*i;
        i++;
    }
    if(i>1)*sum=*sum/(i-1);
    return i-2;
}
