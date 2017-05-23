#include <stdio.h>
#include <string.h>
void reversal(char [],int);
int main()
{
    int t,caseno=0;
    char num[10000];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", num);
        int j=strlen(num);
        if(j%2==0)
        {
            int l=0,i;
            int k=j/2;
            reversal(num,j/2);
            for(i=0;i<j/2;i++,k++)
            {
                if(num[i]==num[k]) continue;
               l=1;break;
            }
            if(l==1) printf("Case %d: No\n",++caseno);
            else printf("Case %d: Yes\n",++caseno);
        }
        else
        {
            int l=0,i;
            int k=(j/2)+1;
            reversal(num,j/2);
            for(i=0;i<j/2;i++,k++)
            {
                if(num[i]==num[k]) continue;
                l=1;break;
            }
            if(l==1) printf("Case %d: No\n",++caseno);
            else printf("Case %d: Yes\n",++caseno);
        }

    }
    return 0;
}
void reversal(char a[],int n)
{
    n=n-1;
    int i=0;
    char x;
    while(i<n)
    {
        x=a[i];
        a[i]=a[n];
        a[n]=x;
        i++;n--;
    }

}
