#include<bits/stdc++.h>
#define MAX 1010

using namespace std;

int arr[MAX];
vector< int > adj[MAX];
bool vis[MAX];

double bfs(int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) adj[i].clear();
        memset(vis, false, sizeof vis);
        int total = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            total += arr[i];
        }
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        double average = ((double)total) / n;
        if(average != (int)average) {
            printf("Case %d: No\n", ++caseno);
            continue;
        }
        bool flag = false;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                double ret = bfs(i);
                if(ret != average) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) printf("Case %d: No\n", ++caseno);
        else printf("Case %d: Yes\n", ++caseno);
    }
    return 0;
}

double bfs(int source) {
    queue< int > q;
    q.push(source);
    vis[source] = true;
    int visited = 1, total = arr[source];
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            if(!vis[v]) {
                vis[v] = true;
                visited++;
                total += arr[v];
                q.push(v);
            }
        }
    }
    return ((double)total) / visited;
}
