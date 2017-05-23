#include <bits/stdc++.h>

using namespace std;

const unsigned int MAX = 35;

char name1[MAX], name2[MAX];
int l1, l2, first;
int dp[MAX][MAX];
bool vis[MAX][MAX], vis2[MAX][MAX][2 * MAX];
long long dp2[MAX][MAX][2 * MAX];

int f(int i, int j) {
    if(i >= l1 || j >= l2) return 0;
    if(vis[i][j]) return dp[i][j];
    vis[i][j] = true;
    int &ret = dp[i][j];
    if(name1[i] == name2[j]) ret = 1 + f(i + 1, j + 1);
    else ret = max(f(i + 1, j), f(i, j + 1));
    return ret;
}

long long variation(int i, int j, int taken) {
    if(i >= l1 || j >= l2) {
        if(taken + l1 - i + l2 - j == first) return 1;
        else return 0;
    }
    if(vis2[i][j][taken]) return dp2[i][j][taken];
    vis2[i][j][taken] = true;
    long long &ret = dp2[i][j][taken];
    if(name1[i] == name2[j]) ret = variation(i + 1, j + 1, taken + 1);
    else {
        ret = variation(i + 1, j, taken + 1) + variation(i, j + 1, taken + 1);
    }
    return ret;
}

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    getchar();
    while(t--) {
        memset(vis, false, sizeof vis);
        memset(vis2, false, sizeof vis2);
        l1 = 0;
        l2 = 0;
        char ch;
        while((ch = getchar()) != '\n') name1[l1++] = ch;
        while((ch = getchar()) != '\n') name2[l2++] = ch;
        first = l1 + l2 - f(0, 0);
        printf("Case %d: %d %lld\n", ++caseno, first, variation(0, 0, 0));
    }
    return 0;
}
