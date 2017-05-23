#include<bits/stdc++.h>
#define MAX 20010

using namespace std;


vector< int > adj[MAX], adjRev[MAX];
set< int > connected;
stack< int > st;
int n, m, sccCount, hostSCC[MAX], indegree[MAX], outdegree[MAX];
bool vis[MAX];

void sccFinder();
void dfs_vis(int);
void dfs_vis2(int, int);
int edgeAdder();

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) {
            adj[i].clear();
            adjRev[i].clear();
            indegree[i] = 0;
            outdegree[i] = 0;
        }
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--, v--;
            adj[u].push_back(v);
            adjRev[v].push_back(u);
        }
        sccFinder();
        printf("Case %d: %d\n", ++caseno, edgeAdder());
    }
    return 0;
}

void sccFinder() {

    for(int i = 0; i < n; i++)
        vis[i] = false;
    while(!st.empty()) st.pop();
    for(int i = 0; i < n; i++) {
        if(!vis[i])
            dfs_vis(i);
    }
    for(int i = 0; i < n; i++)
        vis[i] = false;
    sccCount = 0;
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        if(!vis[u]) {
            connected.clear();
            dfs_vis2(u, sccCount);
            for(set< int >::iterator it = connected.begin(); it != connected.end(); it++) {
                int x = *it;
                outdegree[x]++;
                indegree[sccCount]++;
            }
            sccCount++;
        }
    }
}

void dfs_vis(int u) {
    vis[u] = true;
    for(int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(!vis[v])
            dfs_vis(v);
    }
    st.push(u);
}

void dfs_vis2(int u, int sccNo) {
    vis[u] = true;
    hostSCC[u] = sccNo;
    for(int i = 0; i < (int)adjRev[u].size(); i++) {
        int v = adjRev[u][i];
        if(!vis[v])
            dfs_vis2(v, sccNo);
        else if(hostSCC[v] != hostSCC[u])
            connected.insert(hostSCC[v]);
    }
}

int edgeAdder() {
    if(sccCount == 1) return 0;
    int in = 0, out = 0;
    for(int i = 0; i < sccCount; i++) {
        if(!indegree[i]) in++;
        if(!outdegree[i]) out++;
    }
    return max(in, out);
}
