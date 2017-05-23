#include <stdio.h>
#include <stdlib.h>

int main()
{
   int T,W,N,M,caseno = 1;
   scanf("%d", &T);
   loop: while(T--)
   {
       scanf("%d", &W);
       for(M=2; M<W/2; M=M+2)
       {
           if(W%M==0)
           {
               N=W/M;
               if (N%2==1)
               {
                   printf("Case %d: %d %d\n", caseno++,N,M);

                   goto loop;
               }

           }

       }
       printf("Case %d: Impossible\n", caseno++);


   }
   return 0;

}
