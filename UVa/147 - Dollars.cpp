#include <bits/stdc++.h>
#define MAX 6010
using namespace std;
int coin[] = {2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1};
long long dp[MAX][11];
bool vis[MAX][11];
long long func(int, int);

int main()
{
    double x;
    memset(vis, false, sizeof vis);
    while(scanf("%lf", &x) && x)
    {
        int y = x * 100;
        if(y % 5 != 0) y++;
        printf("%6.2lf%17I64d\n", x, func(y / 5, 0));
    }
    return 0;
}

long long func(int make, int i)
{
    if(i == 11)
    {
        if(make == 0) return 1;
        else return 0;
    }
    if(vis[make][i]) return dp[make][i];
    long long ret1 = 0, ret2 = 0;
    if(make - coin[i] >= 0) ret1 = func(make - coin[i], i);
    ret2 = func(make, i + 1);
    dp[make][i] = ret1 + ret2;
    vis[make][i] = true;
    return dp[make][i];
}
