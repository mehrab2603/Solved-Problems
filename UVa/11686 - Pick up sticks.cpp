#include <bits/stdc++.h>

#define MAX 1000001

using namespace std;
vector<int> adj[MAX];
short col[MAX];
int n, m;
bool flag;
void dfs(int);
vector<int> ans;

int main()
{
    while(scanf("%d %d", &n, &m) && n && m)
    {
        int a, b;
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            adj[b].push_back(a);
        }
        memset(col, 0, sizeof col);
        flag = false;
        for(int i = 1; i <= n; i++)
            if(col[i] == 0)
                dfs(i);
        if(flag)
            printf("IMPOSSIBLE\n");
        else
        {
            for(int i = 0; i < n; i++)
                printf("%d\n", ans[i]);
        }
        ans.clear();
        for(int i = 0; i <= n; i++) adj[i].clear();
    }
    return 0;
}

void dfs(int src)
{
    int u = src;
    col[u] = 1;
    for(int i = 0; i < (int)adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(col[v] == 1) {flag = true; return;}
        else if(col[v] == 0) dfs(v);
    }
    col[u] = 2;
    ans.push_back(u);
    return;
}
