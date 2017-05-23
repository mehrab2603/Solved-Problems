#include <bits/stdc++.h>

using namespace std;
int m, s;
int coinX[50], coinY[50];
bool vis[950][950][50];
int dp[950][950][50];
int func(int, int, int);

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &m, &s);
        s *= s;
        for(int i = 0; i < m; i++)
            scanf("%d %d", &coinX[i], &coinY[i]);
        memset(vis, false, sizeof vis);
        int ans = func(0, 0, 0);
        if(ans > 900) printf("not possible\n");
        else printf("%d\n", ans);
    }
    return 0;
}

int func(int x, int y, int index)
{
    int val = x * x + y * y;
    if(index == m)
    {
        if(val == s) return 0;
        else return 999999;
    }
    if(index < m && val == s) return 0;
    if(val > s) return 999999;
    if(vis[x][y][index]) return dp[x][y][index];
    int ret1 = 999999, ret2 = 999999;
    ret1 = 1 + func(x + coinX[index], y + coinY[index], index);
    ret2 = func(x, y, index + 1);
    vis[x][y][index] = true;
    return dp[x][y][index] = min(ret1, ret2);
}
