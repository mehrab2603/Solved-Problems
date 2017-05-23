#include<bits/stdc++.h>
#define MAX 110

using namespace std;

int arr[MAX][MAX];

int main() {
    //freopen("input.txt", "r", stdin);
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                arr[i][j] = 9999999;
            arr[i][i] = 0;
        }
        while(m--) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            arr[u][v] = min(arr[u][v], w);
            arr[v][u] = min(arr[v][u], w);
        }
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
        printf("Case %d: ", ++caseno);
        if(arr[1][n] == 9999999) printf("Impossible\n");
        else printf("%d\n", arr[1][n]);
    }
    return 0;
}
