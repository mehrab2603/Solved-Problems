#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
long long thunt(int, int);
void TakenItems(int, int);
int ItemNumber(int, int, int);
bool vis[31][1001];
long long dp[31][1001];
int dir[31][1001];
int t, w, n;
int depth[30], value[30];

int main()
{
    int notfirstrun = 0;
    while(scanf("%d %d %d", &t, &w, &n) != EOF)
    {
        if(notfirstrun) puts("");
        notfirstrun = 1;
        for(int i = 0; i < n; i++) scanf("%d %d", &depth[i], &value[i]);
        memset(vis, false, sizeof(vis));
        memset(dir, -1, sizeof(dir));
        printf("%I64d\n", thunt(0, t));
        printf("%d\n",ItemNumber(0, t, 0));
        TakenItems(0, t);
    }
    return 0;
}

long long thunt(int i, int left)
{
    if(i == n) return 0;
    if(vis[i][left] == true) return dp[i][left];
    long long ret1 = -10, ret2 = -10;
    if(left - 3 * w * depth[i] >= 0) ret1 = value[i] + thunt(i + 1, left - 3 * w * depth[i]);
    ret2 = thunt(i + 1, left);
    if(ret1 >= ret2)
    {
        dp[i][left] = ret1;
        vis[i][left] = true;
        dir[i][left] = 1;
    }
    else
    {
        dp[i][left] = ret2;
        vis[i][left] = true;
        dir[i][left] = 2;
    }
    return dp[i][left];
}

void TakenItems(int i, int left)
{
    if(dir[i][left] == -1) return;
    else if(dir[i][left] == 1)
    {
        printf("%d %d\n", depth[i], value[i]);
        TakenItems(i + 1, left - 3 * w * depth[i]);
    }
    else if(dir[i][left] == 2)
    {
        TakenItems(i + 1, left);
    }
}

int ItemNumber(int i, int left, int counter)
{
    if(dir[i][left] == -1) return counter;
    else if(dir[i][left] == 1) return ItemNumber(i + 1, left - 3 * w * depth[i], counter + 1);
    else if(dir[i][left] == 2) return ItemNumber(i + 1, left, counter);
}
