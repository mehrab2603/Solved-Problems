#include<bits/stdc++.h>
#define MAX 210
#define inf 99999999

using namespace std;

int busyness[MAX], dist[MAX];
bool vis[MAX];
vector< int > adj[MAX];

void bellmanford(int, int, int);
void bfs(int);

struct Edge {
    int u, v;
    Edge() {}
    Edge(int a, int b) {u = a; v = b;}
};

vector< Edge > edge;

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n, m, q;
        scanf("%d", &n);
        for(int i = 0; i <= n; i++) {
            adj[i].clear();
            vis[i] = false;
        }
        edge.clear();
        for(int i = 1; i <= n; i++)
            scanf("%d", &busyness[i]);
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            edge.push_back(Edge(u, v));
        }
        scanf("%d", &q);
        printf("Case %d:\n", ++caseno);
        bellmanford(1, n, m);
        while(q--) {
            int dest;
            scanf("%d", &dest);
            if(vis[dest] || dist[dest] == inf || dist[dest] < 3)
                printf("?\n");
            else printf("%d\n", dist[dest]);
        }
    }
    return 0;
}

void bellmanford(int src, int n, int m) {
    for(int i = 1; i <= n; i++)
        dist[i] = inf;
    dist[src] = 0;
    for(int i = 0; i < n; i++) {
        bool updateFlag = false;
        for(int j = 0; j < m; j++) {
            int u = edge[j].u, v = edge[j].v;
            int cost = (busyness[v] - busyness[u]);
            cost = cost * cost * cost;
            if(dist[u] + cost < dist[v] && dist[u] != inf) {
                updateFlag = true;
                dist[v] = dist[u] + cost;
                if(i + 1 == n) bfs(v);
            }
        }
        if(!updateFlag) break;
    }
}

void bfs(int src) {
    vis[src] = true;
    queue< int > q;
    q.push(src);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            if(!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}
