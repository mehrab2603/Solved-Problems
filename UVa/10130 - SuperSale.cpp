#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int maxval(int, int, int);
int dp[1000][40];
int prices[1000], weights[1000];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &prices[i], &weights[i]);
        }
        int g, sum = 0;
        scanf("%d", &g);
        fill(&dp[0][0], &dp[0][0] + (sizeof(dp)/sizeof(int)), -1);
        for(int j = 0; j < g; j++)
        {
            int mw;
            scanf("%d", &mw);
            sum += maxval(n - 1, 0, mw);
        }
        printf("%d\n", sum);
    }
    return 0;
}

int maxval(int n, int i, int mw)
{
    if(i == n + 1) return 0;
    if(dp[i][mw] != -1) return dp[i][mw];
    int maxval1 = 0, maxval2 = 0;
    if(weights[i] <= mw) maxval1 = prices[i] + maxval(n, i + 1,  mw - weights[i]);
    maxval2 = maxval(n, i + 1, mw);
    dp[i][mw] = max(maxval1, maxval2);
    return dp[i][mw];
}
