#include<bits/stdc++.h>
#define MAX 110

using namespace std;

int p, r, bh, of, yh, m, dist[MAX];
vector< int > adj[MAX], cost[MAX], par[MAX];
bool bossPath[MAX];

void bossOfficeDijkstra();
int employeeDijkstra();
void bossNodes(int);

struct Node {
    int node, dist;
    Node(int a, int b) {node = a; dist = b;}
    bool operator<(const Node &n) const {return dist > n.dist;}
};

int main() {
    while(scanf("%d %d %d %d %d %d", &p, &r, &bh, &of, &yh, &m) != EOF) {
        for(int i = 0; i <= p; i++) {
            adj[i].clear();
            cost[i].clear();
            par[i].clear();
            bossPath[i] = false;
        }
        while(r--) {
            int p1, p2, d;
            scanf("%d %d %d", &p1, &p2, &d);
            adj[p1].push_back(p2);
            adj[p2].push_back(p1);
            cost[p1].push_back(d);
            cost[p2].push_back(d);
        }
        bossOfficeDijkstra();
        bossNodes(bh);
        if(bossPath[yh] || bossPath[m]) {printf("MISSION IMPOSSIBLE.\n"); continue;}
        int ans = employeeDijkstra();
        if(ans == -1) printf("MISSION IMPOSSIBLE.\n");
        else printf("%d\n", ans);
    }
    return 0;
}

void bossOfficeDijkstra() {
    memset(dist, 63, sizeof dist);
    priority_queue< Node > q;
    dist[of] = 0;
    par[of].push_back(-1);
    q.push(Node(of, 0));
    while(!q.empty()) {
        Node top = q.top();
        q.pop();
        int u = top.node, udist = top.dist;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i], vcost = cost[u][i];
            if(udist + vcost <= dist[v]) {
                dist[v] = udist + vcost;
                par[v].push_back(u);
                q.push(Node(v, dist[v]));
            }
        }
    }
}

int employeeDijkstra() {
    memset(dist, 63, sizeof dist);
    priority_queue< Node > q;
    dist[yh] = 0;
    q.push(Node(yh, 0));
    while(!q.empty()) {
        Node top = q.top();
        q.pop();
        int u = top.node, udist = top.dist;
        if(u == m) return udist;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i], vcost = cost[u][i];
            if(!bossPath[v] && udist + vcost < dist[v]) {
                dist[v] = udist + vcost;
                if(v == m) return dist[v];
                q.push(Node(v, dist[v]));
            }
        }
    }
    return -1;
}

void bossNodes(int src) {
    bossPath[src] = true;
    if(par[src][0] == -1) return;
    for(int i = 0; i < par[src].size(); i++) {
        if(!bossPath[par[src][i]])bossNodes(par[src][i]);
    }
}
