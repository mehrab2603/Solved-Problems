#include <stdio.h>

int main ()
{
    int t, caseno=0;
    scanf("%d", &t);
    while(t--)
    {
        int i=0, j, k=-1, l;
        int n;
        scanf("%d", &n);
        while(1)
        {
            if (n&(1<<i))
            {
                if (k==-1) {k=l=i;}
                if (n&(1<<(i+1))) {i++;}
                else {break;}
            }
            else {i++;}
        }

       if (i==k)
        {
            n&=~(1<<i);
            n|=(1<<(i+1));
        }
        else
        {
        for(j=0;j<i-k;j++)
        {
            n&=~(1<<l++);
            n|=(1<<j);

        }
        n&=~(1<<l++);
        n|=(1<<l);

        }
        printf("Case %d: %d\n", ++caseno, n);
    }
    return 0;
}
