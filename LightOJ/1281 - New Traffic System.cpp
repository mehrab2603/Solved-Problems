#include <bits/stdc++.h>
#define MAX 10000
#define inf 9999999

using namespace std;
void dijkstra();
vector<int> adj[MAX], adj2[MAX];
vector<int> cost[MAX], cost2[MAX];
long long dist[MAX][11];

struct city
{
    int num, dist, rem;
    city(int a, int b, int c) {num = a; dist = b; rem = c;}
    bool operator < (const city& p) const {return dist > p.dist;}
};
int n, m, k, d;

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d", &n, &m, &k, &d);
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(v);
            cost[u].push_back(w);
        }
        for(int i = 0; i < k; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj2[u].push_back(v);
            cost2[u].push_back(w);
        }
        dijkstra();
        long long result = dist[n - 1][0];
        for(int i = 1; i < 11; i++)
            if(dist[n - 1][i] < result)
                result = dist[n - 1][i];
        if(result == 9187201950435737471)
            printf("Case %d: Impossible\n", ++caseno);
        else
            printf("Case %d: %I64d\n", ++caseno, result);
        for(int i = 0; i < n; i++)
        {
            adj[i].clear();
            adj2[i].clear();
            cost[i].clear();
            cost2[i].clear();
        }
    }

    return 0;
}

void dijkstra()
{
    memset(dist, 0x7f, sizeof(dist));
    priority_queue<city> q;
    dist[0][0] = 0;
    q.push(city(0, dist[0][0], 0));
    while(!q.empty())
    {
        city top = q.top();
        q.pop();
        int u = top.num;
        int utaken = top.rem;
        if(u == n - 1) return;
        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(dist[u][utaken] + cost[u][i] < dist[v][utaken])
            {
                dist[v][utaken] = dist[u][utaken] + cost[u][i];
                q.push(city(v, dist[v][utaken], utaken));
            }
        }
        if(utaken < d)
        {
            for(int i = 0; i < (int)adj2[u].size(); i++)
            {
                    int v = adj2[u][i];
                    if(dist[u][utaken] + cost2[u][i] < dist[v][utaken + 1])
                    {
                        dist[v][utaken + 1] = dist[u][utaken] + cost2[u][i];
                        q.push(city(v, dist[v][utaken + 1], utaken + 1));
                    }
            }
        }
    }
}

