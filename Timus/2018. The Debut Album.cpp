#include <bits/stdc++.h>

using namespace std;

const int MAX = 50005, MOD = 1000000000 + 7;

int n, a, b, dp[MAX][2];

int f(int pos, int song) {
    if(pos == n) return 1;
    else if (pos > n) return 0;
    if(dp[pos][song] != 0) return dp[pos][song];
    int &ret = dp[pos][song];
    if(song) {
        for(int i = 1; i <= b; i++) ret = (ret + (f(pos + i, 0) % MOD)) % MOD;
    }
    else {
        for(int i = 1; i <= a; i++) ret = (ret + (f(pos + i, 1) % MOD)) % MOD;
    }
    return ret;
}



int main() {
    scanf("%d %d %d", &n, &a, &b);

    printf("%d\n", (f(0, 0) % MOD + f(0, 1) % MOD) % MOD);
    return 0;
}
