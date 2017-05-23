#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) && (n || m)) {
        set<int> cd;
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            cd.insert(x);
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            int x;
            scanf("%d", &x);
            if(cd.find(x) != cd.end())
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
