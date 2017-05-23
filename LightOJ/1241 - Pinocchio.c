#include <stdio.h>

int main()
{
   int t,n, caseno=0;
   scanf("%d", &t);
   while (t--)
   {
       int i,countno=0;
       scanf("%d", &n);
       int arr[n];
       for(i=0;i<n;i++)
       {
        scanf("%d", &arr[i]);

       }
       for(i=0; i<n; i++)
       {
           int k,l= arr[i],m=arr[i-1];
           if(i==0) k=l-2;
           else k=l-m;
           countno+=k/5;
           k= k%5;
           countno+=k/4;
           k= k%4;
           countno+=k/3;
           k= k%3;
           countno+=k/2;
           k= k%2;
           countno+=k/1;


        }
           printf("Case %d: %d\n", ++caseno, countno);
     }

       return 0;
   }
