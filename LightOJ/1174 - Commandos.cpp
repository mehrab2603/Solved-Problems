#include<bits/stdc++.h>
#define MAX 110

using namespace std;

int arr[MAX][MAX];

int main() {
    //freopen("input.txt", "r", stdin);
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n, r;
        scanf("%d %d", &n, &r);
        memset(arr, 63, sizeof arr);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                arr[i][j] = 99999;
            }
            arr[i][i] = 0;
        }
        while(r--) {
            int u, v;
            scanf("%d %d", &u, &v);
            arr[u][v] = 1;
            arr[v][u] = 1;
        }
        int s, d;
        scanf("%d %d", &s, &d);
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
        int ans = -1;
        for(int i = 0; i < n; i++) {
            ans = max(ans, arr[s][i] + arr[i][d]);
        }
        printf("Case %d: %d\n", ++caseno, ans);
    }
    return 0;
}
