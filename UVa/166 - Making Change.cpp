#include <bits/stdc++.h>

using namespace std;
int shopMake(int, int);
int custMake(int, int);
int coins[] = {1, 2, 4, 10, 20, 40}, amount[6];
bool vis[150][6];
int dp[150][6], dp2[150][6];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(vis, false, sizeof vis);
    for(int i = 1; i <= 100; i++)
        shopMake(i, 0);
    double temp;
    while(scanf("%d %d %d %d %d %d %lf", &amount[0], &amount[1], &amount[2], &amount[3], &amount[4], &amount[5], &temp) && (amount[0] || amount[1] || amount[2] || amount[3] || amount[4] || amount[5]))
    {
        temp = (temp * 100) / 5;
        int make = (int)(temp + .000000001);
        memset(vis, false, sizeof vis);
        int test;
        if(make + 40 <= 140) test = make + 40;
        else test = 140;
        for(int i = make; i <= test; i++)
            custMake(i, 0);
        int ans = dp2[make][0];
        for(int i = make + 1; i <= test; i++)
            ans = min(ans, dp2[i][0] + dp[i - make][0]);
        printf("%3d\n", ans);
        temp = 0;
    }
    return 0;
}

int shopMake(int make, int index)
{
    if(index == 6)
    {
        if(!make) return 0;
        else return 999999;
    }
    if(index < 6 && !make) return 0;
    if(vis[make][index]) return dp[make][index];
    int ret1 = 999999, ret2 = 999999;
    if(make - coins[index] >= 0) ret1 = 1 + shopMake(make - coins[index], index);
    ret2 = shopMake(make, index + 1);
    vis[make][index] = true;
    return dp[make][index] = min(ret1, ret2);
}

int custMake(int make, int index)
{
    if(index == 6)
    {
        if(!make) return 0;
        else return 999999;
    }
    if(index < 6 && !make) return 0;
    if(vis[make][index]) return dp2[make][index];
    int ret1 = 999999, ret2 = 999999;
    for(int i = 1; i <= amount[index]; i++)
        if(make - i * coins[index] >= 0) ret1 = min(ret1, i + custMake(make - i * coins[index], index + 1));
    ret2 = custMake(make, index + 1);
    vis[make][index] = true;
    return dp2[make][index] = min(ret1, ret2);
}
