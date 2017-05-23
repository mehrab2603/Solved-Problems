#include <bits/stdc++.h>

using namespace std;
int arr[210];
int n, q, d, m;
int dp[210][15][25];
bool vis[210][15][25];
long long func(int, int, int);

int main()
{
    int caseno = 0;
    while(scanf("%d %d", &n, &q) && (n || q)) {
        printf("SET %d:\n", ++caseno);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        int queryno = 0;
        for(int i = 0; i < q; i++) {
            scanf("%d %d", &d, &m);
            memset(vis, false, sizeof vis);
            printf("QUERY %d: %lld\n", ++queryno, func(0, 0, 0));
        }
    }
    return 0;
}

long long func(int i, int taken, int sum) {
    if(sum < 0) {
        int def = (sum * (-1)) / d;
        sum = sum + ((def + 1) * d);
    }
    if(taken > m) return 0;
    if(taken == m) {
        if(sum % d == 0) return 1;
        else return 0;
    }
    if(i >= n) return 0;
    if(vis[i][taken][sum]) return dp[i][taken][sum];
    long long ret1 = func(i + 1, taken + 1, (sum + arr[i]) % d);
    long long ret2 = func(i + 1, taken, sum);
    vis[i][taken][sum] = true;
    return dp[i][taken][sum] = ret1 + ret2;
}
