#include <bits/stdc++.h>
#define MAX 10001

using namespace std;
void dfs();
void dfs_visit(int);
vector<int> adj[MAX];
vector<int> apoints;
int col[MAX], par[MAX], dis[MAX], low[MAX], call[MAX], tim, n, src;

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        int m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs();
        printf("Case %d: %d\n", ++caseno, apoints.size());
        apoints.clear();
        for(int i = 1; i <= n; i++)
            adj[i].clear();
    }

    return 0;
}

void dfs()
{
    memset(col, 0, sizeof(col));
    memset(par, -1, sizeof(par));
    memset(dis, 63, sizeof(dis));
    memset(low, 63, sizeof(low));
    memset(call, 0, sizeof(call));
    tim = 0;
    for(int i = 1; i <= n; i++)
    {
        if(col[i] == 0)
        {
            src = i;
            dfs_visit(src);
            if(call[src] > 1)
                apoints.push_back(src);
        }
    }
}

void dfs_visit(int u)
{
    dis[u] = ++tim;
    col[u] = 1;
    low[u] = dis[u];
    bool flag = false;
    for(int i = 0; i < (int)adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(par[u] == v) continue;
        if(col[v] == 0)
        {
            call[u]++;
            par[v] = u;
            dfs_visit(v);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dis[u] && u != src && !flag)
            {
                apoints.push_back(u);
                flag = true;
            }
        }
        else
            low[u] = min(low[u], dis[v]);
    }
}
