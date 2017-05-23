#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, n, caseno=0;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        getchar();
        scanf("%d", &n);
        int a[n],sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
            if(a[i]<0) continue;
            sum=sum+a[i];
        }
        printf("Case %d: %d\n", ++caseno, sum);

    }
    return 0;
}
