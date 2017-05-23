#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector< int > node[110];
vector< int > answer;


int main()
{
    while(1)
    {
        int dep[110] = {0};
        bool vis[110] = {0};
        int m, n;
        scanf("%d %d", &n, &m);
        if(m == 0 && n == 0) break;
        int u, v;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d", &u, &v);
            dep[v]++;
            node[u].push_back(v);
        }
        int k = 1;
        for(; k <= n; k++)
        {
            if(dep[k] == 0 && vis[k] == 0)
            {
                answer.push_back(k);
                vis[k] = 1;
                for(int l = 0; l < node[k].size(); l++)
                {
                    int q = node[k][l];
                    dep[q]--;
                }
                k = 0;
            }
        }
        for(int x = 0; x < answer.size(); x++)
            printf("%d ", answer[x]);
        printf("\n");
        for(int a = 1; a <= n; a++)
        node[a].clear();
        answer.clear();

    }
    return 0;
}
