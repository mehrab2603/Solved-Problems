#include<bits/stdc++.h>
#define MAX 1010

using namespace std;

int n, m, dist[MAX], edgeU[2 * MAX], edgeV[2 * MAX], edgeCost[2 * MAX], vis[MAX];
vector< int > adj[MAX];
set< int > ans;

void bfs(int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) {
            adj[i].clear();
            dist[i] = 99999999;
            vis[i] = false;
        }
        ans.clear();
        for(int i = 0; i < m; i++) {
            int x, y, t;
            scanf("%d %d %d", &x, &y, &t);
            adj[y].push_back(x);
            edgeU[i] = y;
            edgeV[i] = x;
            edgeCost[i] = t;
        }
        dist[0] = 0;
        for(int i = 0; i < n; i++) {
            bool updateFlag = false;
            for(int j = 0; j < m; j++) {
                int u = edgeU[j], v = edgeV[j], weight = edgeCost[j];
                if(dist[u] + weight < dist[v]) {
                    updateFlag = true;
                    if(i + 1 == n) {
                        bfs(u);
                    }
                    dist[v] = dist[u] + weight;
                }
            }
            if(!updateFlag) break;
        }
        printf("Case %d:", ++caseno);
        if(ans.size() == 0) printf(" impossible\n");
        else {
            for(set< int >::iterator it = ans.begin(); it != ans.end(); it++)
                printf(" %d", *it);
            printf("\n");
        }
    }
    return 0;
}

void bfs(int src) {
    ans.insert(src);
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
                ans.insert(v);
                q.push(v);
            }
        }
    }
}

