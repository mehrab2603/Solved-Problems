#include<bits/stdc++.h>
#define MAX 30010

using namespace std;
vector< int > adj[MAX], cost[MAX];
bool vis[MAX];

struct Node {
    int node, dist;
    Node() {}
    Node(int a, int b) {node = a; dist = b;}
};

int firstBFS();
int secondBFS(int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            adj[i].clear();
            cost[i].clear();
        }
        for(int i = 0; i < n - 1; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        printf("Case %d: %d\n", ++caseno, secondBFS(firstBFS()));
    }
    return 0;
}

int firstBFS() {
    memset(vis, false, sizeof vis);
    queue< Node > q;
    vis[0] = true;
    q.push(Node(0, 0));
    int maxDistance = 0, farthestNode = -1;
    while(!q.empty()) {
        Node front = q.front();
        q.pop();
        int u = front.node, udist = front.dist;
        for(int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            if(!vis[v]) {
                vis[v] = true;
                if(udist + cost[u][i] > maxDistance) {
                    maxDistance = udist + cost[u][i];
                    farthestNode = v;
                }
                q.push(Node(v, udist + cost[u][i]));
            }
        }
    }
    return farthestNode;
}

int secondBFS(int source) {
    memset(vis, false, sizeof vis);
    queue< Node > q;
    vis[source] = true;
    q.push(Node(source, 0));
    int maxDistance = 0;
    while(!q.empty()) {
        Node front = q.front();
        q.pop();
        int u = front.node, udist = front.dist;
        for(int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            if(!vis[v]) {
                vis[v] = true;
                if(udist + cost[u][i] > maxDistance) maxDistance = udist + cost[u][i];
                q.push(Node(v, udist + cost[u][i]));
            }
        }
    }
    return maxDistance;
}
