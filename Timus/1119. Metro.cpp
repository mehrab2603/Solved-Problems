#include<bits/stdc++.h>

using namespace std;

const int MAX = 1005, inf = 10000000;
const double diagonal = sqrt(2) * 100, eps = 1e-10;

int n, m;
double dp[MAX][MAX];
bool vis[MAX][MAX], cross[MAX][MAX];

double f(int x, int y) {
    if(x > n || y > m) return inf;
    if(x == n && y == m) return 0;
    if(vis[x][y]) return dp[x][y];
    vis[x][y] = true;
    return dp[x][y] = min(100 + f(x + 1, y), (cross[x][y] ? min(100 + f(x, y + 1), diagonal + f(x + 1, y + 1)) : 100 + f(x, y + 1)));
}


int main() {
    scanf("%d %d", &n, &m);
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        cross[x - 1][y - 1] = true;
    }
    double ans = f(0, 0);
    double high = ceil(ans);
    double low = floor(ans);
    printf("%d\n", high - ans < ans - low ? (int)high : (int)low);

    return 0;
}
