#include <bits/stdc++.h>
#define MAX 101

using namespace std;
vector<int> adj[MAX];
int n, s, ld, ln;
void bfs();

int main()
{
    int caseno = 0;
    while(scanf("%d", &n) && n)
    {
        scanf("%d", &s);
        int p, q;
        while(scanf("%d %d", &p, &q) && p && q)
        {
            adj[p].push_back(q);
        }
        bfs();
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++caseno, s, ld, ln);
        for(int i = 0; i <= n; i++)
            adj[i].clear();
    }
    return 0;
}

void bfs()
{
    ld = -1;
    ln = 999;
    int dist[MAX];
    memset(dist, 0, sizeof dist);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(dist[u] + 1 >= dist[v])
            {
                dist[v] = dist[u] + 1;
                if(dist[v] >= ld)
                    ld = dist[v];
                q.push(v);
            }
        }
    }
    for(int i = 1; i <= n; i++)
        if(dist[i] == ld)
            if(i < ln)
                ln = i;
}
