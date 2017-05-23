#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

map<string, int>node;
vector< string > bev;
vector< int > edge[110];
vector < int > answer;

int main()
{
    int m, n, caseno = 0;
    while(scanf("%d", &n) != EOF)
    {
        int dep[110] = {0};
        bool vis[110] = {0};
        int num = 0;
        string c1;
        for(int i = 0; i < n; i++)
        {
            cin >> c1;
            bev.push_back(c1);
            node[c1] = num++;
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            string c2, c3;
            cin >> c2 >> c3;
            int u = node[c2];
            int v = node[c3];
            dep[v]++;
            edge[u].push_back(v);
        }
        int k = 0;
        for(; k < n; k++)
        {
            if(dep[k] == 0 && vis[k] == 0)
            {
                answer.push_back(k);
                vis[k] = 1;
                for(int l = 0; l < edge[k].size(); l++)
                {
                    int q = edge[k][l];
                    dep[q]--;
                }
                k = -1;
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order: ", ++caseno);
        int x = 0;
        for(; x < answer.size() - 1; x++)
        {
            int z = answer[x];
            cout << bev[z] << " ";
        }
        int z = answer[x];
        cout << bev[z] <<"." << endl << endl;
        for(int a = 0; a <= n; a++)
        edge[a].clear();
        answer.clear();
        node.clear();
        bev.clear();
    }

    return 0;
}
