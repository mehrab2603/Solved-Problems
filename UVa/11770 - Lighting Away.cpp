#include <bits/stdc++.h>

using namespace std;
vector<int> adj[10000];
vector<int> top;
void dfs(int);
int col[10000];

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            a--, b--;
            adj[a].push_back(b);
        }
        memset(col, 0, sizeof(col));
        for(int i = 0; i < n; i++)
            if(col[i] == 0)
                dfs(i);
        int countno = 0;
        memset(col, 0, sizeof(col));
        for(int i = n - 1; i >= 0; i--)
        {
            int u = top[i];
            if(col[u] == 0)
            {
                dfs(u);
                countno++;
            }
        }
        printf("Case %d: %d\n", ++caseno, countno);
        for(int i = 0; i < n; i++)
            adj[i].clear();
        top.clear();
    }
    return 0;
}

void dfs(int src)
{
    int u = src;
    col[src] = 1;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(col[v] == 0)
            dfs(v);
    }
    top.push_back(u);
    col[u] = 2;
}
