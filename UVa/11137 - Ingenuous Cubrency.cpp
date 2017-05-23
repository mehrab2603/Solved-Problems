#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
long long ncounter(int, int);
int values[21];
int make;
long long dp[21][10000];

int main()
{
    for(int i = 0; i < 21; i++) values[i] = (i + 1) * (i + 1) * (i + 1);
    while(scanf("%d", &make) == 1)
    {
        memset(dp, -1, sizeof(dp));
        printf("%I64d\n", ncounter(0, make));
    }
    return 0;
}

long long ncounter(int i, int make)
{
    if(i == 21)
    {
        if(make == 0) return 1;
        else return 0;
    }
    if(dp[i][make] != -1) return dp[i][make];
    long long ret1 = 0, ret2 = 0;
    if(make - values[i] >= 0) ret1 = ncounter(i, make - values[i]);
    ret2 = ncounter(i + 1, make);
    dp[i][make] = ret1 + ret2;
    return dp[i][make];
}
