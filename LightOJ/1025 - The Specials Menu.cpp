#include <bits/stdc++.h>

using namespace std;

const int MAX = 65;

char input[MAX];
long long dp[MAX][MAX];
bool vis[MAX][MAX];

long long func(int i, int j) {
    if(i > j) return 0;
    long long &ret = dp[i][j];
    if(vis[i][j]) return ret;
    vis[i][j] = true;
    if(input[i] == input[j]) return ret = 1 + func(i + 1, j - 1) + func(i, j - 1) + func(i + 1, j) - func(i + 1, j - 1);
    else return ret = func(i, j - 1) + func(i + 1, j) - func(i + 1, j - 1);
}

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    getchar();
    while(t--) {
        scanf("%s%*c", input);
        memset(vis, false, sizeof vis);
        printf("Case %d: %lld\n", ++caseno, func(0, strlen(input) - 1));
    }
    return 0;
}
