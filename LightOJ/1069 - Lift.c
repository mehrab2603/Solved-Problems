#include <stdio.h>


int main()
{
    int t,mpos,lpos,caseno=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&mpos,&lpos);
        int diff=mpos-lpos;
        if(diff<0)diff*=-1;
        printf("Case %d: %d\n",++caseno,diff*4+mpos*4+19);
    }
    return 0;
}
