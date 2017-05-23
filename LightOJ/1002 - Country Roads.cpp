#include<bits/stdc++.h>
#define MAX 510

using namespace std;

int n, m, d, dist[MAX];

class DisjointSet {
private:
    vector<int> par, ran;
public:
    DisjointSet(int n) {
        par.assign(n, 0);
        ran.assign(n, 0);
        for(int i = 0; i < n; i++)
            par[i] = i;
    }

    int findSet(int x) {
        return (par[x] == x) ? x : par[x] = findSet(par[x]);
    }

    bool isSameSet(int x, int y) {
        return findSet(x) == findSet(y);
    }

    void unionSet(int x, int y) {
        if(!isSameSet(x, y)) {
            int parX = par[x], parY = par[y];
            if(ran[parX] > ran[parY]) par[parY] = parX;
            else {
                par[parX] = parY;
                if(ran[parX] == ran[parY])
                    ran[parY]++;
            }
        }
    }
};

struct Road {
    int u, v, w;
    Road() {}
    Road(int a, int b, int c) {u = a; v = b; w = c;}
    bool operator<(const Road &r) const {return w < r.w;}
};

struct Node {
    int node, dist;
    Node() {}
    Node(int a, int b) {node = a; dist = b;}
};

Road road[16010];
vector< int > adj[MAX], cost[MAX];

void kruskal();
void bfs();

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            road[i] = Road(u, v, w);
        }
        scanf("%d", &d);
        printf("Case %d:\n", ++caseno);
        for(int i = 0; i < n; i++) {
            adj[i].clear();
            cost[i].clear();
        }
        for(int i = 0; i < n; i++)
            dist[i] = -1;
        kruskal();
        bfs();
        for(int i = 0; i < n; i++) {
            if(dist[i] == -1) printf("Impossible\n");
            else printf("%d\n", dist[i]);
        }

    }
    return 0;
}

void kruskal() {
    sort(road, road + m);
    memset(adj, 0, sizeof adj);
    DisjointSet ds(n);
    int counter = 0;
    for(int i = 0; i < m; i++) {
        Road currentRoad = road[i];
        if(!ds.isSameSet(currentRoad.u, currentRoad.v)) {
            ds.unionSet(currentRoad.u, currentRoad.v);
            adj[currentRoad.u].push_back(currentRoad.v);
            adj[currentRoad.v].push_back(currentRoad.u);
            cost[currentRoad.u].push_back(currentRoad.w);
            cost[currentRoad.v].push_back(currentRoad.w);
            counter++;
            if(counter == n - 1) break;
        }
    }
}

void bfs() {
    bool vis[510] = {false};
    queue< Node > q;
    vis[d] = true;
    dist[d] = 0;
    q.push(Node(d, 0));
    while(!q.empty()) {
        Node top = q.front();
        q.pop();
        int u = top.node, udist = top.dist;
        for(int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i], vdist = cost[u][i];
            if(!vis[v]) {
                vis[v] = true;
                dist[v] = max(udist, vdist);
                q.push(Node(v, dist[v]));
            }
        }
    }
    return;
}
