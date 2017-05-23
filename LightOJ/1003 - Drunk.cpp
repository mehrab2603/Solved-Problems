#include <bits/stdc++.h>

using namespace std;
map <string, int> mymap;
vector<int> adj[10000];
int col[10000], nodes;
int flag;
void dfs(int);

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        int m;
        scanf("%d", &m);
        int assig = 0;
        for(int i = 0; i < m; i++)
        {
            string a, b;
            cin >> a;
            if(mymap.find(a) == mymap.end())
            {
                mymap[a] = assig;
                assig++;
            }
            cin >> b;
            if(mymap.find(b) == mymap.end())
            {
                mymap[b] = assig;
                assig++;
            }
            int x = mymap[a], y = mymap[b];
            adj[x].push_back(y);
        }
        nodes = assig;
        flag = 0;
        memset(col, 0, sizeof(col));
        for(int i = 0; i < nodes; i++)
            if(col[i] == 0)
                dfs(i);
        if(flag) printf("Case %d: No\n", ++caseno);
        else printf("Case %d: Yes\n", ++caseno);
        mymap.clear();
        for(int i = 0; i < nodes; i++) adj[i].clear();
    }
    return 0;
}


void dfs(int src)
{
    int u = src;
    col[u] = 1;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(col[v] == 0)
            dfs(v);
        else if(col[v] == 1) flag = 1;
    }
    col[u] = 2;
}

