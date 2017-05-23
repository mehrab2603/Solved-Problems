#include<bits/stdc++.h>
#define MAX 110

using namespace std;

int n, m, c, s, t, price[MAX], cost[MAX][MAX];
vector< int > adj[MAX], dist[MAX];
struct Node {
    int node, fuel, cost;
    Node() {}
    Node(int a, int b, int c) {node = a; fuel = b; cost = c;}
    bool operator<(const Node &n) const {return cost > n.cost;}
};

int dijkstra();

int main() {
    int tc, caseno = 0;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%d", &price[i]);
        for(int i = 0; i < n; i++) {
            adj[i].clear();
            dist[i].clear();
        }
        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(v);
            adj[v].push_back(u);
            dist[u].push_back(w);
            dist[v].push_back(w);
        }
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", ++caseno);
        while(q--) {
            scanf("%d %d %d", &c, &s, &t);
            int ans = dijkstra();
            if(ans == -1)
                printf("impossible\n");
            else
                printf("%d\n", ans);
        }
    }
    return 0;
}

int dijkstra() {
    memset(cost, 63, sizeof cost);
    priority_queue< Node > q;
    cost[s][0] = 0;
    q.push(Node(s, 0, 0));
    while(!q.empty()) {
        Node top = q.top();
        q.pop();
        int u = top.node, ufuel = top.fuel, ucost = top.cost;
        if(u == t) return ucost;
        for(int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i], vdist = dist[u][i];
            int offset = vdist - ufuel;
            if(offset < 0) offset = 0;
            for(int j = ufuel + offset; j <= c; j++) {
                if(ucost + price[u] * (j - ufuel) < cost[v][j - vdist]) {
                    cost[v][j - vdist] = ucost + price[u] * (j - ufuel);
                    q.push(Node(v, j - vdist, cost[v][j - vdist]));
                    if(v == t) break;
                }
            }
        }
    }
    return -1;
}
