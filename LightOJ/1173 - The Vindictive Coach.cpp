#include <bits/stdc++.h>

using namespace std;

const int MAX = 60;
const unsigned long long MOD = pow(2, 64);

char input[MAX];
unsigned long long dp[MAX][MAX][2];

unsigned long long func(int lowCount, int highCount, bool direction) {
    if((lowCount == 0 && highCount == 1 && !direction) || (lowCount == 1 && highCount == 0 && direction)) return 1;
    unsigned long long &ret = dp[lowCount][highCount][direction];
    if(ret) return ret;
    ret = 0;
    if(direction) {
        for(int i = 1; i <= lowCount; i++) ret = (ret + func(lowCount - i, highCount + i - 1, !direction) % MOD) % MOD;
    }
    else {
        for(int i = 1; i <= highCount; i++) ret = (ret + func(lowCount + i - 1, highCount - i, !direction) % MOD) % MOD;
    }
    return ret;
}


int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    getchar();
    while(t--) {
        int m, n;
        scanf("%d %d", &m, &n);
        printf("Case %d: %llu\n", ++caseno, (n == 1 ? (m > 2 ? func(1, m - 3, true) : 1) : func(n - 1, m - n, true)));
    }
    return 0;
}
