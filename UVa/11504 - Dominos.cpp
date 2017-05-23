#include <bits/stdc++.h>
#define MAX 100001

using namespace std;
int n, m;
vector<int> adj[MAX];
int col[MAX];
stack<int> topsort;
void dfs1();
void dfs_vis1(int);
int dfs2();
void dfs_vis2(int);

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
        }
        dfs1();
        int ans = dfs2();
        printf("%d\n", ans);
        for(int i = 0; i <= n; i++)
            adj[i].clear();
    }
    return 0;
}

void dfs1()
{
    memset(col, 0, sizeof col);
    for(int i = 1; i <=n; i++)
        if(col[i] == 0)
            dfs_vis1(i);
}

void dfs_vis1(int src)
{
    int u = src;
    col[u] = 1;
    for(int i = 0; (int)i < (int)adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(col[v] == 0)
            dfs_vis1(v);
    }
    col[u] = 2;
    topsort.push(u);
}

int dfs2()
{
    memset(col, 0, sizeof col);
    int ans = 0;
    while(!topsort.empty())
    {
        int i = topsort.top();
        topsort.pop();
        if(col[i] == 0)
            ans++, dfs_vis2(i);
    }
    return ans;
}

void dfs_vis2(int src)
{
    int u = src;
    col[u] = 1;
    for(int i = 0; i < (int)adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(col[v] == 0)
            dfs_vis2(v);
    }
    col[u] = 2;
}
