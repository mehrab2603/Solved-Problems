#include <cstdio>
using namespace std;

long long dp[505][505];

long long func(int last, int rem) {
    if(rem == 0) return 1;
    long long &ret = dp[last][rem];
    if(ret != -1) return ret;
    ret = func(last + 1, rem - 1);
    if(last && rem > last) ret += func(last + 1, rem - last - 1);

    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++) dp[i][j] = -1;
    printf("%lld\n", func(0, n) - 1);
	return 0;
}
