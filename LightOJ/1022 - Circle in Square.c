#include <stdio.h>
#include <math.h>
#define pi  2*acos(0.0)

int main()
{
   int t,caseno=0;
   double r;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%lf", &r);
       printf("Case %d: %.2lf\n", ++caseno, r*r*(4-pi));
   }
   return 0;
}
