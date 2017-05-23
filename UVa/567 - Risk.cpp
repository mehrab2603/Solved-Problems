#include <bits/stdc++.h>

using namespace std;
int bfs(int, int);
vector<int> adj[20];

int main()
{
    int caseno = 0;
    while(1)
    {
        for(int i = 0; i < 19; i++)
        {
            int num;
            int ret = scanf("%d", &num);
            if(ret == EOF) return 0;
            for(int j = 0; j < num; j++)
            {
                int x;
                scanf("%d", &x);
                x--;
                adj[i].push_back(x);
                adj[x].push_back(i);
            }
        }
        int n;
        scanf("%d", &n);
        printf("Test Set #%d\n", ++caseno);
        for(int i = 0; i < n; i++)
        {
            int source, destination;
            scanf("%d %d", &source, &destination);
            printf("%2d to %2d: ", source, destination);
            source--, destination--;
            printf("%d\n", bfs(source, destination));
        }
        printf("\n");
        for(int i = 0; i < 20; i++) adj[i].clear();
    }
    return 0;
}


int bfs(int src, int dest)
{
    int taken[20] = {0};
    int dist[20];
    queue<int> q;
    q.push(src);
    taken[src] = 1;
    dist[src] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!taken[v])
            {
                taken[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[dest];
}
