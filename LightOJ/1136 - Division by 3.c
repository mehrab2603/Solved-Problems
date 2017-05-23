#include <stdio.h>
int main()
{
    int i,j,k,l,t, caseno=0;
    scanf("%d", &t);
    while(t--)
    {
        int a,b,dcount=0;
        scanf("%d %d", &a,&b);
        for(i=a;;)
        {
            if (b%3==0) {k=b;l=b-1;}
            else if (b%3==1) {k=b-1;l=b-2;}
            else {k=b-2;l=b;}

            if (i%3==0)
            {
                dcount= 2+ ((k-i)/3) + ((l-(i+2))/3);
                break;

            }

            else if (i%3==2)
            {
                dcount= 2+ ((l-i)/3) + ((k-(i+1))/3);
                break;

            }
            else i++;

        }

        printf("Case %d: %d\n", ++caseno, dcount);

    }
    return 0;
}
