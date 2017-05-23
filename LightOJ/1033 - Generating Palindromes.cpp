#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;
char input[MAX];
int dp[MAX][MAX];
bool vis[MAX][MAX];

int func(int i, int j) {
    if(i >= j) return 0;
    int &ret = dp[i][j];
    if(vis[i][j]) return ret;
    vis[i][j] = true;
    ret = INT_MAX;
    if(input[i] != input[j]) ret = 1 + min(func(i, j - 1), func(i + 1, j));
    else ret = func(i + 1, j - 1);
    return ret;
}

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    getchar();
    while(t--) {
        scanf("%s%*c", input);
        memset(vis, false, sizeof vis);
        printf("Case %d: %d\n", ++caseno, func(0, strlen(input) - 1));
    }
    return 0;
}
