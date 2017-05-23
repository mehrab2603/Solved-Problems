#include <bits/stdc++.h>

using namespace std;
void bfs(int);
map<string, int> mymap;
vector<int> adj[1009];
int parent[1009];
int dist[1009];

int main()
{
    int n;
    bool flag = false;
    while(scanf("%d", &n) != EOF)
    {
        if(flag == false) flag = true;
        else printf("\n");
        int assig = 0;
        for(int i = 0; i < n; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            if(mymap.find(s1) == mymap.end())
            {
                mymap[s1] = assig;
                assig++;
            }
            if(mymap.find(s2) == mymap.end())
            {
                mymap[s2] = assig;
                assig++;
            }
            int u = mymap[s1];
            int v = mymap[s2];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string s1, s2;
        cin >> s1 >> s2;
        if(s1 == s2) {printf("%s %s\n", s1.c_str(), s2.c_str());mymap.clear(); for(int i = 0; i < assig; i++) adj[i].clear(); continue;}
        if(mymap.find(s1) == mymap.end() || mymap.find(s2) == mymap.end()) {printf("No route\n");mymap.clear(); for(int i = 0; i < assig; i++) adj[i].clear(); continue;}
        int start = mymap[s1], finish = mymap[s2];
        memset(parent, -1, sizeof(parent));
        memset(dist, 0, sizeof(dist));
        bfs(start);
        if(dist[finish] == 0) printf("No route\n");
        else
        {
            stack<int> s;
            int it = finish;
            while(it != start)
            {
                s.push(it);
                it = parent[it];
            }
            s.push(it);
            while(!s.empty())
            {
                int city = s.top();
                s.pop();
                if(city == start)
                {
                    printf("%s ", s1.c_str());
                }
                else if(city == finish)
                {
                    printf("%s\n", s2.c_str());

                }
                else
                {
                    map<string, int>::iterator pos;
                    for(pos = mymap.begin(); pos != mymap.end(); pos++)
                    {
                        if(pos->second == city)
                        {
                            string s3 = pos->first;
                            printf("%s\n%s ", s3.c_str(), s3.c_str());
                        }
                    }
                }
            }
        }
        mymap.clear();
        for(int i = 0; i < assig; i++) adj[i].clear();
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    bool taken[1001] = {false};
    taken[start] = true;
    parent[start] = -1;
    dist[start] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!taken[v])
            {
                taken[v] = true;
                parent[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
