#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
int bfs(int);
vector< int > edge[201];

int main()
{

    while(1)
    {
        int n, l;
        scanf("%d", &n);
        if(n == 0) break;
        scanf("%d", &l);
        for(int i = 0; i < l; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        if(bfs(0))
            printf("NOT BICOLORABLE.\n");
        else
            printf("BICOLORABLE.\n");
        for(int i = 0; i < n; i++)
            edge[i].clear();
    }
    return 0;
}

int bfs(int src)
{
    queue< int > q;
    int col[201] = {0};
    q.push(src);
    col[src] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < edge[u].size(); i++)
        {
            int v = edge[u][i];
            if(col[v] == 0)
            {
                if(col[u] == 1)
                    col[v] = 2;
                else
                    col[v] = 1;
                q.push(v);
            }
            else
            {
                if(col[v] == col[u])
                    return 1;
            }
        }
    }
    return 0;
}
