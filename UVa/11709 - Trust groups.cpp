#include <bits/stdc++.h>

using namespace std;

map<string, int> mymap;
vector<int> adj[1000];
vector<int> adj2[1000];
int col[1000];
int counter;
stack<int> st;
int DFS();
void DFSvisit(int);
void DFSvisit2(int);

int main()
{
    string line;
    while(getline(cin, line))
    {
        istringstream is(line);
        int p, t;
        is >> p >> t;
        if(p == 0 && t == 0) break;
        counter = 0;
        for(int i = 0; i < p; i++)
        {
            string s1;
            getline(cin, s1);
            if(mymap.find(s1) == mymap.end())
            {
                mymap[s1] = counter;
                counter++;
            }
        }
        for(int i = 0; i < t; i++)
        {
            string s1, s2;
            getline(cin, s1);
            getline(cin, s2);
            int u = mymap[s1];
            int v = mymap[s2];
            adj[u].push_back(v);
            adj2[v].push_back(u);
        }
        int ans = DFS();
        printf("%d\n", ans);
        mymap.clear();
        for(int i = 0; i < counter; i++)
        {
            adj[i].clear();
            adj2[i].clear();
        }

    }
    return 0;
}

int DFS()
{
    int counter2 = 0;
    memset(col, 0, sizeof(col));
    for(int i = 0; i < counter; i++)
        if(col[i] == 0)
            DFSvisit(i);
    memset(col, 0, sizeof(col));
    while(!st.empty())
    {
        int u = st.top();
        st.pop();

        if(col[u] == 0)
        {
            DFSvisit2(u);
            counter2++;
        }
    }
    return counter2;
}

void DFSvisit(int u)
{
    col[u] = 1;
    for(int i = 0; i < (int)adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(col[v] == 0)
            DFSvisit(v);
    }
    col[u] = 2;
    st.push(u);
}

void DFSvisit2(int u)
{
    col[u] = 1;
    for(int i = 0; i < (int)adj2[u].size(); i++)
    {
        int v = adj2[u][i];
        if(col[v] == 0)
            DFSvisit2(v);
    }
    col[u] = 2;
}
