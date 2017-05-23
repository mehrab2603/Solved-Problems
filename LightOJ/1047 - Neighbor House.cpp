#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 1<<28

using namespace std;
long long mincost(int, int, int, int);
int arr[20][3];
long long dp[20][3];
int n;

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 3; j++)
                scanf("%d", &arr[i][j]);
        memset(dp, -1, sizeof(dp));
        long long ret = inf;
        for(int k = 0; k < 3; k++) ret = min(ret, mincost(0, k, n, 3));
        printf("Case %d: %I64d\n", ++caseno, ret);
    }
    return 0;
}

long long mincost(int i, int j, int r, int c)
{
    if(i >= 0 && i < r && j >= 0 && j < c)
    {
        if(dp[i][j] != -1) return dp[i][j];
        long long ret = inf;
        if(j == 0)
        {
            ret = min(ret, arr[i][j] + mincost(i + 1, 1, r, c));
            ret = min(ret, arr[i][j] + mincost(i + 1, 2, r, c));
        }
        if(j == 1)
        {
            ret = min(ret, arr[i][j] + mincost(i + 1, 0, r, c));
            ret = min(ret, arr[i][j] + mincost(i + 1, 2, r, c));
        }
        if(j == 2)
        {
            ret = min(ret, arr[i][j] + mincost(i + 1, 0, r, c));
            ret = min(ret, arr[i][j] + mincost(i + 1, 1, r, c));
        }
        dp[i][j] = ret;
        return dp[i][j];
    }
    else return 0;
}
