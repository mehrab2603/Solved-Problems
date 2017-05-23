#include <bits/stdc++.h>

using namespace std;

const int MAX = 505;
double dp[MAX][MAX][2];
bool vis[MAX][MAX][2];

double func(int r, int b, int player) {
    if(!player) {
        if(r == 1 && b == 0) return 0;
        else if(r == 0 && b == 1) return 1;
    }
    double &ret =  dp[r][b][player];
    if(vis[r][b][player]) return ret;
    vis[r][b][player] = true;
    ret = 0;
    if(player) {
        if(b) ret = b * (1.0 / b) * func(r, b - 1, 0);
    }
    else {
        if(r) ret += r * (1.0 / (r + b)) * func(r - 1, b, 1);
        if(b) ret += b * (1.0 / (r + b)) * func(r, b - 1, 1);
    }
    return ret;
}

void precalc() {
    for(int i = 500; i >= 0; i--)
        for(int j = 500; j >= 0; j--)
            func(i, j, 0);
}

int main() {
    precalc();
    int t, caseno = 0;
    scanf("%d", &t);
    getchar();
    while(t--) {
        int r, b;
        scanf("%d %d", &r, &b);
        printf("Case %d: %.10g\n", ++caseno, dp[r][b][0]);
    }
    return 0;
}
