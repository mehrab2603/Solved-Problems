#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int t,i, caseno=0;
    char num1[255];
    long long num2;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s %lld", num1, &num2);
        if(num1[0]=='0'){printf("Case %d: divisible\n", ++caseno);continue;}
        if(num2<0) num2=num2*(-1);
        long long sum=0;
        if(num1[0]!='-')i=0;
        else i=1;
        while(num1[i]!='\0')
        {
            sum=(sum*10)+(num1[i]-'0');
            if(sum%num2==sum){i++;continue;}
            sum=sum%num2;
            i++;

        }
            if (sum==0) {printf("Case %d: divisible\n", ++caseno);}
            else {printf("Case %d: not divisible\n", ++caseno);}

    }

    return 0;

}
