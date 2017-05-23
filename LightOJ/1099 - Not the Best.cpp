#include <bits/stdc++.h>
#define inf 9999999
#define MAX 5001

using namespace std;
int dijkstra(int, int);
int dijkstra2(int, int);
int n, r;
int par[MAX];
int dist[MAX];
vector<int> adj[MAX];
vector<int> cost[MAX];
struct node
{
    int u, w;
    node(int a, int b) {u = a; w = b;}
    bool operator < (const node& p) const {return w > p.w;}
};

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &r);
        for(int i = 0; i < r; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        int sd = dijkstra(1, n);
        int x = n, ans = inf;
        while(x != -1)
        {
            int u = x;
            for(int j = 0; j < (int)adj[u].size(); j++)
            {
                int v = adj[u][j];
                int ssd = dijkstra2(v, n);
                int tempdist = dist[u] + cost[u][j] + ssd;
                if(tempdist > sd && tempdist < ans)
                    ans = tempdist;
            }
            x = par[x];
        }
        printf("Case %d: %d\n", ++caseno, ans);
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
            cost[i].clear();
        }

    }
    return 0;
}

int dijkstra(int src, int dest)
{
    fill(&dist[0], &dist[0] + n + 1, inf);
    fill(&par[0], &par[0] + n + 1, -1);
    //memset(dist, 63, sizeof(dist));
    //memset(par, -1, sizeof(par));
    dist[src] = 0;
    priority_queue<node> q;
    q.push(node(src, dist[src]));
    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        int u = top.u;
        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(dist[u] + cost[u][i] < dist[v])
            {
                par[v] = u;
                dist[v] = dist[u] + cost[u][i];
                q.push(node(v, dist[v]));
            }
        }
    }
    return dist[dest];
}

int dijkstra2(int src, int dest)
{
    int dist2[n + 1];
    fill(&dist2[0], &dist2[0] + n + 1, inf);
    //memset(dist2, 63, sizeof(dist2));
    dist2[src] = 0;
    priority_queue<node> q;
    q.push(node(src, dist2[src]));
    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        int u = top.u;
        if(u == dest) return dist2[dest];
        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(dist2[u] + cost[u][i] < dist2[v])
            {
                dist2[v] = dist2[u] + cost[u][i];
                q.push(node(v, dist2[v]));
            }
        }
    }
    return -1;
}
