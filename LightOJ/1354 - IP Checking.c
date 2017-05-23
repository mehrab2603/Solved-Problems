#include <stdio.h>
#include <math.h>
int toDec(long int);
int main()
{
    int T,a1,a2,a3,a4,caseno=0;
    long int b1,b2,b3,b4;

    scanf("%d", &T);


    while(T--)
    {
        scanf("%d.%d.%d.%d",&a1,&a2,&a3,&a4);

        scanf("%ld.%ld.%ld.%ld",&b1,&b2,&b3,&b4);


        if(a1==toDec(b1)&&a2==toDec(b2)&&a3==toDec(b3)&&a4==toDec(b4)) printf("Case %d: Yes\n", ++caseno);
        else printf("Case %d: No\n", ++caseno);
    }
    return 0;
}
int toDec(long int x)
{

    int i,count=0,sum=0;
    for(i=1;i<9;i++)
    {
        if(x%10==1)
        {
            sum=sum+pow(2,count);
            count++;
            x=x/10;
        }
        else {x=x/10;count++;}

    }
    return sum;
}
