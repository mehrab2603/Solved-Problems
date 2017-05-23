#include <bits/stdc++.h>
#define MAX 101

using namespace std;
void dfs();
void dfs_visit(int);
vector<int> input;
vector<int> adj[MAX];
int col[MAX], dis[MAX], low[MAX], par[MAX], call[MAX], counter, n, src, tim;

int main()
{
    while(scanf("%d", &n) && n)
    {
        getchar();
        string s1;
        while(getline(cin, s1) && s1 != "0")
        {
            istringstream is(s1);
            int x;
            while(is >> x)
                input.push_back(x);
            int u = input[0];
            for(int i = 1; i < (int)input.size(); i++)
            {
                int v = input[i];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            input.clear();
        }
        dfs();
        printf("%d\n", counter);
        for(int i = 1; i <= n; i++)
            adj[i].clear();

    }
    return 0;
}

void dfs()
{
    memset(col, 0, sizeof(col));
    memset(dis, 63, sizeof(dis));
    memset(low, 63, sizeof(dis));
    memset(par, -1, sizeof(par));
    memset(call, 0, sizeof(call));
    counter = 0;
    tim = 0;
    for(int i = 1; i <= n; i++)
    {
        if(col[i] == 0)
        {
            src = i;
            dfs_visit(src);
            if(call[src] > 1)
                counter++;
        }
    }
}

void dfs_visit(int u)
{
    col[u] = 1;
    dis[u] = ++tim;
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
                counter++;
                flag = true;
            }
        }
        else
            low[u] = min(low[u], dis[v]);
    }
}
