#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,caseno=0;
    scanf("%d", &t);
    //freopen("out.txt","w",stdout);
    while(t--)
    {
        int m,n,i,x,itemcount=0;
        int deq[12]={786,786,786,786,786,786,786,786,786,786,786,786};
        char command[100];
        scanf("%d %d", &n, &m);
        printf("Case %d:\n",++caseno);
        while(m--)
        {
            scanf("%s",command);
            if(command[4]=='L')
            {
                scanf("%d", &x);
                if(itemcount>=n)
                {
                    printf("The queue is full\n");
                    continue;
                }
                for(i=n;i>=1;i--)
                {
                    if(deq[i]==786) continue;
                    deq[i+1]=deq[i];
                    deq[i]=786;
                }
                deq[i+1]=x;
                itemcount++;
                printf("Pushed in left: %d\n",x);
            }
            else if(command[4]=='R')
            {
                scanf("%d", &x);
                if(itemcount>=n)
                {
                    printf("The queue is full\n");
                    continue;
                }
                for(i=1;i<=n;i++)
                {
                    if(deq[i]==786) continue;
                    deq[i-1]=deq[i];
                    deq[i]=786;
                }
                deq[i-2]=x;
                itemcount++;
                printf("Pushed in right: %d\n",x);
            }
            else if(command[4]=='e')
            {
                if(itemcount<=0)
                {
                    printf("The queue is empty\n");
                    continue;
                }
                for(i=0;i<=n;i++)
                {
                    if(deq[i]!=786)
                    {
                        printf("Popped from left: %d\n",deq[i]);
                        deq[i]=786;
                        itemcount--;
                        break;
                    }
                }

            }
            else if(command[4]=='i')
            {
                if(itemcount<=0)
                {
                    printf("The queue is empty\n");
                    continue;
                }
                for(i=n;i>=0;i--)
                {
                    if(deq[i]!=786)
                    {
                        printf("Popped from right: %d\n",deq[i]);
                        deq[i]=786;
                        itemcount--;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
