#include <bits/stdc++.h>

using namespace std;

map<int, int> input;
vector<int> adj[30];
int bfs(int, int, int);

const int inf = 999999;

int main()
{
    int nc, caseno = 0;
    while(scanf("%d", &nc) && nc)
    {
        int assig = 0;
        for(int i = 0; i < nc; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            if(input.find(x) == input.end())
            {
                input[x] = assig;
                assig++;
            }
            if(input.find(y) == input.end())
            {
                input[y] = assig;
                assig++;
            }
            x = input[x];
            y = input[y];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int n, ttl;
        while(scanf("%d %d", &n, &ttl) && (n || ttl))
        {
            int source = input[n];
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++caseno, bfs(source, ttl, assig), n, ttl);
        }
        input.clear();
        for(int i = 0; i < assig; i++) adj[i].clear();
    }
    return 0;
}


int bfs(int src, int ttl, int nodes)
{
    int taken[30] = {0};
    int distance[30];
    int counter = 0;
    queue <int> q;
    q.push(src);
    distance[src] = 0;
    taken[src] = 1;
    nodes--;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!taken[v])
            {
                distance[v] = distance[u] + 1;
                if(distance[v] > ttl) counter++;
                taken[v] = 1;
                nodes--;
                q.push(v);
            }
        }
    }
    return counter + nodes;
}
