#include <bits/stdc++.h>

using namespace std;
int values[] = {1, 5, 10, 25, 50};
long long cc(int, int);
long long dp[5][30001];
bool vis[5][30001];
long long preans[30001];

int main()
{
    int x;
    memset(vis,false, sizeof vis);
    for(int i = 0; i <= 30001; i++)
        preans[i] = cc(0, i);
    while(scanf("%d", &x) != EOF)
    {
        long long ans = preans[x];
        if(ans != 1)
            cout << "There are " << ans << " ways to produce " << x << " cents change." << endl;
        else
            printf("There is only 1 way to produce %d cents change.\n", x);
    }
}

long long cc(int i, int left)
{
    if(i == 5)
    {
        if(left == 0)
            return 1;
        else return 0;
    }
    if(vis[i][left] == true) return dp[i][left];
    long long ret1 = 0, ret2 = 0;
    if(left - values[i] >= 0) ret1 = cc(i, left - values[i]);
    ret2 = cc(i + 1, left);
    dp[i][left] = ret1 + ret2;
    vis[i][left] = true;
    return dp[i][left];
}
