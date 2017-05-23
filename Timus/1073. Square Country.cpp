#include <bits/stdc++.h>

using namespace std;

int n, dp[60005];

int f(int left) {
    if(left < 0) return INT_MAX;
    if(left == 0) return 0;
    if(dp[left]) return dp[left];
    dp[left] = INT_MAX;
    for(int i = 1; i * i <= left; i++) dp[left] = min(dp[left], 1 + f(left - i * i));
    return dp[left];
}

int main() {
    scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}
