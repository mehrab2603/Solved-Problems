#include <bits/stdc++.h>

using namespace std;

const int MAX = 50010;

int n, sccSize[MAX], sccNumber, belongsTo[MAX], dp[MAX];
vector< int > adj[MAX], adjReverse[MAX];
unordered_set< int > adjNew[MAX];
bool vis[MAX];
stack< int > finishOrder;

int dfs();
void dfs_vis1(int);
void dfs_vis2(int);
int dfs_vis3(int);

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i <= n; i++) {
            sccSize[i] = 0;
            belongsTo[i] = -1;
            adjNew[i].clear();
            adjReverse[i].clear();
            adj[i].clear();
        }
        for(int i = 0; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adjReverse[v].push_back(u);
        }
        printf("Case %d: %d\n", ++caseno, dfs());
    }
    return 0;
}

int dfs() {
    while(!finishOrder.empty()) finishOrder.pop();
    memset(vis, false, sizeof vis);
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfs_vis1(i);
    memset(vis, false, sizeof vis);
    sccNumber = 0;
    while(!finishOrder.empty()) {
        int u = finishOrder.top();
        finishOrder.pop();
        if(!vis[u]) {
            sccNumber++;
            dfs_vis2(u);
        }
    }
    memset(vis, false, sizeof vis);
    int maximumReach = INT_MIN;
    vector< int > scc;
    for(int i = 1; i <= sccNumber; i++) {
        if(!vis[i]) {
            int ret = dfs_vis3(i);
            if(ret > maximumReach) {
                maximumReach = ret;
                scc.clear();
                scc.push_back(i);
            }
            else if(ret == maximumReach) scc.push_back(i);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < (int)scc.size(); j++)
        if(belongsTo[i] == scc[j])
            return i;
    }
    return -1;
}

void dfs_vis1(int u) {
    vis[u] = true;
    for(int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(!vis[v])
            dfs_vis1(v);
    }
    finishOrder.push(u);
}

void dfs_vis2(int u) {
    vis[u] = true;
    belongsTo[u] = sccNumber;
    for(int i = 0; i < (int)adjReverse[u].size(); i++) {
        int v = adjReverse[u][i];
        if(!vis[v])
            dfs_vis2(v);
        else if(belongsTo[v] != sccNumber) {
            adjNew[belongsTo[v]].insert(sccNumber);
        }
    }
    sccSize[sccNumber]++;
}

int dfs_vis3(int u) {
    if(vis[u]) return dp[u];
    int ret = sccSize[u] - 1;
    for(unordered_set< int >::iterator it = adjNew[u].begin(); it != adjNew[u].end(); it++) {
        int v = *it;
        ret += dfs_vis3(v) + 1;
    }
    vis[u] = true;
    dp[u] = ret;
    return dp[u];
}
