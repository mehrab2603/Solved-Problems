#include<bits/stdc++.h>
#define MAX 101

using namespace std;

vector< int > adj[MAX], cost[MAX];
bool vis[MAX];

int bfs();

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i <= n; i++)
            adj[i].clear(), cost[i].clear();
        for(int i = 0; i < n; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(0);
            cost[v].push_back(w);
        }
        printf("Case %d: %d\n", ++caseno, bfs());
    }
    return 0;
}

int bfs() {
    memset(vis, false, sizeof vis);
    queue< int > q;
    q.push(1);
    vis[1] = true;
    int cost1 = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < (int)adj[u].size(); i++) {
            if(u == 1 && i == 1) continue;
            int v = adj[u][i];
            if(!vis[v] || (v == 1 && u != adj[1][0])) {
                vis[v] = true;
                cost1 += cost[u][i];
                q.push(v);
            }
        }
    }
    memset(vis, false, sizeof vis);
    q.push(1);
    vis[1] = true;
    int cost2 = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < (int)adj[u].size(); i++) {
            if(u == 1 && i == 0) continue;
            int v = adj[u][i];
            if(!vis[v] || (v == 1 && u != adj[1][1])) {
                vis[v] = true;
                cost2 += cost[u][i];
                q.push(v);
            }
        }
    }
    return min(cost1, cost2);
}
