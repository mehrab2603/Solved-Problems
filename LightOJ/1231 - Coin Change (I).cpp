#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int wfinder(int, int, int);
int values[60], numbers[60];
long long dp[50][1009];

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) scanf("%d", &values[i]);
        for(int i = 0; i < n; i++) scanf("%d", &numbers[i]);
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", ++caseno, wfinder(0, k, n - 1) % 100000007);
    }
    return 0;
}

int wfinder(int i, int left, int coins)
{
    if(i == coins + 1)
    {
        if(left == 0) return 1;
        else return 0;
    }
    if(dp[i][left] != -1) return dp[i][left];
    int ret1 = 0, ret2 = 0;
    for(int j = 1; j <= numbers[i]; j++)
    {
        if(left - (j * values[i]) >= 0) ret1 += wfinder(i + 1, left - (j * values[i]), coins) % 100000007;
    }
    ret2 = wfinder(i + 1, left, coins) % 100000007;
    dp[i][left] = (ret1 + ret2) % 100000007;
    return dp[i][left];
}
