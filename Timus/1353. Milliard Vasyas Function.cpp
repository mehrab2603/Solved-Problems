#include <bits/stdc++.h>

using namespace std;

int s, dp[10][85];

int f(int pos, int sum) {
    if(pos == 10) {
        if(sum == s) return 1;
        else return 0;
    }
    if(sum > 81) return 0;
    if(dp[pos][sum] != -1) return dp[pos][sum];
    int &ret = dp[pos][sum];
    ret = f(pos + 1, sum);
    for(int i = 1; i < 10; i++) ret += f(pos + 1, sum + i);
    return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    memset(dp, -1, sizeof dp);
    scanf("%d", &s);
    int ans = f(1, 0);
    if(s == 1) ans++;
    printf("%d\n", ans);
    return 0;
}
