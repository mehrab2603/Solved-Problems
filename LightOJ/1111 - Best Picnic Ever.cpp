#include<bits/stdc++.h>
#define MAX 1010

using namespace std;

int reach[MAX];
vector< int > start, adj[MAX];
bool vis[MAX];
void bfs(int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        start.clear();
        int k, n, m;
        scanf("%d %d %d", &k, &n, &m);
        for(int i = 0; i <= n; i++) adj[i].clear(), reach[i] = 0;
        for(int i = 0; i < k; i++) {
            int x;
            scanf("%d", &x);
            start.push_back(x);
        }
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }
        for(int i = 0; i < k; i++) bfs(start[i]);
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(reach[i] == k)
                ans++;
        printf("Case %d: %d\n", ++caseno, ans);
    }
    return 0;
}

void bfs(int source) {
    memset(vis, false, sizeof vis);
    queue< int > q;
    vis[source] = true;
    reach[source]++;
    q.push(source);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            if(!vis[v]) {
                vis[v] = true;
                reach[v]++;
                q.push(v);
            }
        }
    }
}
