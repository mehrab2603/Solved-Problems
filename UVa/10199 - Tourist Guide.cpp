#include <bits/stdc++.h>
#define MAX 101

using namespace std;
map<string, int> mymap;
vector<int> adj[MAX];
vector<int> apoints;
int col[MAX], par[MAX], low[MAX], dis[MAX], call[MAX], tim, n;
void dfs();
void dfs_visit(int);
int source;

int main()
{
    //freopen("output.txt", "w", stdout);
    int caseno = 0;
    bool start = false;
    while(scanf("%d", &n) && n)
    {
        if(start == false) start = true;
        else cout << endl;
        int assig = 0;
        string places[100];
        for(int i = 0; i < n; i++)
        {
            string s1;
            cin >> s1;
            if(mymap.find(s1) == mymap.end())
            {
                mymap[s1] = assig;
                places[assig] = s1;
                assig++;
            }
        }
        int r;
        scanf("%d", &r);
        for(int i = 0; i < r; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            int u = mymap[s1];
            int v = mymap[s2];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs();
        vector<string> output;
        for(int i = 0; i < (int)apoints.size(); i++)
            output.push_back(places[apoints[i]]);
        sort(output.begin(), output.end());
        printf("City map #%d: %d camera(s) found\n", ++caseno, output.size());
        for(int i = 0; i < (int)output.size(); i++)
            cout << output[i] << endl;
        mymap.clear();
        apoints.clear();
        for(int i = 0; i < n; i++)
            adj[i].clear();
    }
    return 0;
}

void dfs()
{
    memset(low, 63, sizeof(low));
    memset(col, 0, sizeof(col));
    memset(par, -1, sizeof(par));
    memset(dis, 63, sizeof(dis));
    memset(call, 0, sizeof(call));
    tim = 0;
    for(int i = 0; i < n; i++)
    {
        if(col[i] == 0)
        {
            source = i;
            dfs_visit(i);
            if(call[source] > 1)
                apoints.push_back(source);
        }
    }
}

void dfs_visit(int u)
{
    dis[u] = ++tim;
    col[u] = 1;
    low[u] = dis[u];
    bool flag = false;
    for(int i = 0; i < (int)adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(par[u] == v) continue;
        if(col[v] == 1)
            low[u] = min(low[u], dis[v]);
        else
        {
            par[v] = u;
            call[u]++;
            dfs_visit(v);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dis[u] && u != source && !flag)
            {
                apoints.push_back(u);
                flag = true;
            }

        }

    }
}
