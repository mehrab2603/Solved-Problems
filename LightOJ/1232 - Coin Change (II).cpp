#include <bits/stdc++.h>

using namespace std;

const int MAX = 105, MOD = 100000007;

int p, dp[MAX], coins[MAX];


int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) scanf("%d", &coins[i]);
        for(int i = 0; i <= k; i++) dp[i] = 0;
        dp[0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = coins[i]; j <= k; j++)
                dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
        printf("Case %d: %d\n", ++caseno, dp[k]);
    }
    return 0;
}
