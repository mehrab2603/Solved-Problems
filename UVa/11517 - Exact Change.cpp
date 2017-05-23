#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int coins[110];
bool vis[10010][110];
int dp[10010][110], n;
int func(int, int);

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int make;
        scanf("%d %d", &make, &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &coins[i]);
        memset(vis, false, sizeof vis);
        int ans = func(make, 0);
        while(ans > 100)
        {
            make++;
            ans = func(make, 0);
        }
        printf("%d %d\n", make, ans);
    }
    return 0;
}

int func(int make, int index)
{
    if(index >= n)
    {
        if(!make) return 0;
        else return 999999;
    }
    if(index < n && make == 0) return 0;
    if(vis[make][index]) return dp[make][index];
    int ret1 = 999999, ret2 = 999999;
    if(make - coins[index] >= 0) ret1 = 1 + func(make - coins[index], index + 1);
    ret2 = func(make, index + 1);
    vis[make][index] = true;
    dp[make][index] = min(ret1, ret2);
    return dp[make][index];
}
