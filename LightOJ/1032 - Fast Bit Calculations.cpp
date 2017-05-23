#include <bits/stdc++.h>

using namespace std;

bool bits[35];
long long dp[2][35][2][35];
bool vis[2][35][2][35];
int powerOfTwo[35];

long long func(int previous, int index, int flip, int sum) {
    if(index < 0) return sum;
    long long &ret = dp[previous][index][flip][sum];
    if(vis[previous][index][flip][sum]) return ret;
    vis[previous][index][flip][sum] = true;
    ret = 0;
    if(previous && bits[index]) sum++;

    ret += func(bits[index], index - 1, flip, sum);
    if(bits[index]) ret += func(false, index - 1, true, previous ? sum - 1 : sum);
    if(flip && !bits[index]) ret += func(true, index - 1, flip, previous ? sum + 1 : sum);
    return ret;
}

int main() {
    powerOfTwo[0] = 1;
    for(int i = 1; i < 31; i++) powerOfTwo[i] = 2 * powerOfTwo[i - 1];

    int t, caseno = 0;
    scanf("%d", &t);
    getchar();
    while(t--) {
        int n;
        scanf("%d", &n);
        int index = 0;
        while(n) {
            if(n & 1) bits[index++] = true;
            else bits[index++] = false;
            n >>= 1;
        }
        memset(vis, false, sizeof vis);
        printf("Case %d: %lld\n", ++caseno, func(false, index - 2, true, 0) + func(true, index - 2, false, 0));
    }
    return 0;
}
