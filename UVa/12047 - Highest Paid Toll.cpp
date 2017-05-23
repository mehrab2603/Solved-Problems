#include<bits/stdc++.h>
#define MAX 10010

using namespace std;

int n, m, s, t, p, startDist[MAX], endDist[MAX];
vector< int > adj[MAX], adjRev[MAX], toll[MAX], tollRev[MAX];
struct Node {
    int node, tollPaid;
    Node() {}
    Node(int a, int b) {node = a; tollPaid = b;}
    bool operator<(const Node &n) const {return tollPaid > n.tollPaid;}
};
struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int a, int b, int c) {u = a; v = b; w = c;}
    bool operator<(const Edge &e) const {return w > e.w;}
};

vector< Edge > edges;

void dijkstra(int);

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);
        s--, t--;
        for(int i = 0; i < n; i++) {
            adj[i].clear();
            adjRev[i].clear();
            toll[i].clear();
            tollRev[i].clear();
        }
        edges.clear();
        for(int i = 0; i < m; i++) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            u--, v--;
            adj[u].push_back(v);
            toll[u].push_back(c);
            adjRev[v].push_back(u);
            tollRev[v].push_back(c);
            edges.push_back(Edge(u, v, c));
        }
        dijkstra(0);
        dijkstra(1);
        int ans = -1;
        for(int i = 0; i < (int)edges.size(); i++) {
            int u= edges[i].u, v = edges[i].v, edgeToll = edges[i].w;
            if(startDist[u] != INT_MAX && endDist[v] != INT_MAX && (startDist[u] + edgeToll + endDist[v] <= p)) ans = max(ans, edgeToll);
        }
        printf("%d\n", ans);
    }
    return 0;
}

void dijkstra(int mode) {
    priority_queue< Node > q;
    if(mode) {
        for(int i = 0; i < n; i++) endDist[i] = INT_MAX;
        endDist[t] = 0;
        q.push(Node(t, 0));
    }
    else {
        for(int i = 0; i < n; i++) startDist[i] = INT_MAX;
        startDist[s] = 0;
        q.push(Node(s, 0));
    }
    while(!q.empty()) {
        Node top = q.top();
        q.pop();
        int u = top.node, uTollPaid = top.tollPaid;
        if(mode) {
            for(int i = 0; i < (int)adjRev[u].size(); i++) {
                int v = adjRev[u][i], vToll = tollRev[u][i];
                if(uTollPaid + vToll < endDist[v]) {
                    endDist[v] = uTollPaid + vToll;
                    q.push(Node(v, endDist[v]));
                }
            }
        }
        else {
            for(int i = 0; i < (int)adj[u].size(); i++) {
                int v = adj[u][i], vToll = toll[u][i];
                if(uTollPaid + vToll < startDist[v]) {
                    startDist[v] = uTollPaid + vToll;
                    q.push(Node(v, startDist[v]));
                }
            }
        }
    }
}
