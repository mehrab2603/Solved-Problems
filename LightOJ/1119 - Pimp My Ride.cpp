#include <bits/stdc++.h>

using namespace std;

int setBit(int, int);
int resetBit(int, int);
bool checkBit(int, int);
int func(int);
int cost[15][15], n;
int dp[(1 << 14) + 2];
bool vis[(1 << 14) + 2];

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &cost[i][j]);
        memset(vis, false, sizeof vis);
        printf("Case %d: %d\n", ++caseno, func(0));
    }
    return 0;
}

int setBit(int n, int pos) {return n | (1 << pos);}
int resetBit(int n, int pos) {return n & ~(1 << pos);}
bool checkBit(int n, int pos) {return n & (1 << pos);}

int func(int mask)
{
    if(mask == (1 << n) - 1) return 0;
    if(vis[mask]) return dp[mask];
    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(!checkBit(mask, i))
        {
            int bill = cost[i][i];
            for(int j = 0; j < n; j++)
                if(checkBit(mask, j))
                    bill += cost[i][j];
            ans = min(ans, bill + func(setBit(mask, i)));
        }
    }
    vis[mask] = true;
    dp[mask] = ans;
    return dp[mask];
}
