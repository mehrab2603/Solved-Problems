#include <stdio.h>
#include <math.h>

int main()
{
   int t,a,b,caseno=0;
   scanf("%d", &t);
   while(t--)
   {
       scanf("%d %d", &a, &b);
       if (a>b)
       {
           int tmp=b;
           b=a;
           a=tmp;
       }
       if (a==1) printf ("Case %d: %d\n",++caseno, b);

       else if (a==2)
       {
           if (b%4==1 || b%4==3) printf ("Case %d: %d\n",++caseno, b+1);
           else if (b%4==2) printf ("Case %d: %d\n",++caseno, b+2);
           else printf ("Case %d: %d\n",++caseno, b);

       }
       else
       {

           printf ("Case %d: %g\n",++caseno, ceil((a*b)/2.0));
       }


   }
   return 0;
}
