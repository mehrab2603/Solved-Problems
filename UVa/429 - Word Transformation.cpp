#include <bits/stdc++.h>

using namespace std;
vector<int> adj[200];
int dif(string, string);
int bfs(int, int);

int main()
{
    int t;
    scanf("%d", &t);
    bool flag = false;
    while(t--)
    {
        if(flag == false) flag = true;
        else printf("\n");
        map<string, int> mymap;
        vector<string> si[11];
        int assig = 0;
        string s1;
        while(cin >> s1 && s1 != "*")
        {
            if(mymap.find(s1) == mymap.end())
            {
                mymap[s1] = assig;
                assig++;
            }
            int u = mymap[s1];
            int w = s1.size();
            for(int i = 0; i < si[w].size(); i++)
            {
                if(dif(si[w][i], s1))
                {
                    int v = mymap[si[w][i]];
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
            si[w].push_back(s1);
        }
        size_t pos;
        string line;
        getline(cin, line);
        getline(cin, line);
        while(line != "")
        {
            pos = line.find(" ");
            string s2, s3;
            s2 = line.substr(0, pos);
            s3 = line.substr(pos + 1, line.size());
            int ret = bfs(mymap[s2], mymap[s3]);
            printf("%s %s %d\n", s2.c_str(), s3.c_str(), ret);
            if(!getline(cin,line))
                break;
        }
        for(int i = 0; i < assig; i++)
            adj[i].clear();
    }
    return 0;
}

int dif(string s1, string s2)
{
    int countno = 0;
    bool flag = false;
    for(int i = 0; i < s1.size(); i++)
    {
        if(s1[i] != s2[i]) countno++;
        if(countno > 1)
        {
            flag = true;
            break;
        }
    }
    if(flag == false) return 1;
    else return 0;
}

int bfs(int st, int ed)
{
    queue<int> q;
    bool taken[200] = {false};
    int dist[200] = {0};
    taken[st] = true;
    dist[st] = 0;
    q.push(st);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u == ed) return dist[u];
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!taken[v])
            {
                taken[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[ed];
}
