#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
long long wcounter(long long, long long);
long long coins[] = {50, 25, 10, 5, 1};
long long dp[5][7490];

int main()
{
    long long x;
    memset(dp, -1, sizeof(dp));
    while(scanf("%I64d", &x) == 1)
    {
        printf("%I64d\n", wcounter(0, x));
    }
    return 0;
}

long long wcounter(long long i, long long x)
{
    if(i >= 5)
    {
        if(x == 0) return 1;
        else return 0;
    }
    if(dp[i][x] != -1) return dp[i][x];
    long long ret1 = 0, ret2 = 0;
    if(x - coins[i] >= 0) ret1 = wcounter(i, x - coins[i]);
    ret2 = wcounter(i + 1, x);
    dp[i][x] = ret1 + ret2;
    return dp[i][x];
}
