#include <bits/stdc++.h>

using namespace std;

long long fib[] = {1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903,2971215073,4807526976,7778742049,12586269025};

int main()
{
    int n;
    long long ansm[50], anst[50];
    ansm[0] = 0, anst[0] = 1;
    for(int i = 1; i <= 45; i++)
    {
        ansm[i] = anst[i - 1];
        anst[i] = anst[i - 1] + fib[i - 1];
    }
    while(scanf("%d", &n) && n != -1)
        printf("%I64d %I64d\n", ansm[n], anst[n]);
    return 0;
}






