#include <bits/stdc++.h>

int dp[15][15];
bool vis[15][15];
int arr[10];

int func(int, int);
int m, n;

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        memset(vis, false, sizeof vis);
        scanf("%d %d", &m, &n);
        for(int i = 0; i < m; i++) scanf("%d", &arr[i]);
        int ans = 0;
        for(int i = 0; i < m; i++)
            ans += func(n - 1, arr[i]);
        printf("Case %d: %d\n", ++caseno, ans);
    }
    return 0;
}

int func(int nn, int start) {
    if(nn == 0) return 1;

    if(vis[nn][start]) return dp[nn][start];

    int ret = 0;
    for(int i = 0; i < m; i++) {
        int diff = start - arr[i];
        if(diff < 0) diff *= -1;
        if(diff <= 2) ret += func(nn - 1, arr[i]);
    }

    vis[nn][start] = true;
    return dp[nn][start] = ret;
}
