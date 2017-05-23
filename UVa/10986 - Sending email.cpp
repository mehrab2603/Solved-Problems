#include <bits/stdc++.h>
#define MAX 20000

using namespace std;
vector<int> adj[MAX];
vector<int> cost[MAX];
int n, m, s, t;
int dijkstra(int, int);
struct node
{
    int u, w;
    node(int a, int b) {u = a; w = b;}
    bool operator < (const node& p) const {return w > p.w;}
};

int main()
{
    int tt, caseno = 0;
    scanf("%d", &tt);
    while(tt--)
    {
        scanf("%d %d %d %d", &n, &m, &s, &t);
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            adj[a].push_back(b);
            adj[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        int ans = dijkstra(s, t);
        if(ans == -1)
            printf("Case #%d: unreachable\n", ++caseno);
        else
            printf("Case #%d: %d\n", ++caseno, ans);
        for(int i = 0; i < n; i++)
        {
            adj[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}

int dijkstra(int src, int dest)
{
    int dist[MAX];
    for(int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    priority_queue<node> q;
    q.push(node(src, 0));
    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        int u = top.u;
        if(u == dest)
            return dist[u];
        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(dist[u] + cost[u][i] < dist[v])
            {
                dist[v] = dist[u] + cost[u][i];
                q.push(node(v, dist[v]));
            }
        }
    }
    return -1;
}
