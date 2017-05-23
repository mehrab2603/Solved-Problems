#include <stdio.h>


int main()
{
    int t, caseno=0;
    scanf("%d", &t);
    while(t--)
    {
        int n,balance = 0;
        scanf("%d", &n);
        int flag = 0;
        while(n--)
        {
            char command[100];
            scanf("%s", command);
            if(command[0]=='d')
            {
                long x;
                scanf("%ld", &x);
                balance = balance + x;
            }
            else if(command[0]=='r')
            {
                if(flag==0) printf("Case %d:\n",++caseno);
                printf("%d\n",balance);
                flag = 1;
            }
        }
    }
    return 0;
}
