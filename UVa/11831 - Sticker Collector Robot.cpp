#include <bits/stdc++.h>

using namespace std;
string mat[110], command;
struct node
{
    int x, y, dir, candy, com;
    node() {}
    node(int a, int b) {x = a; y = b;}
    node(int a, int b, int c) {x = a; y = b; dir = c;}
    node(int a, int b, int c, int d) {x = a; y = b; dir = c; candy = d;}
    node(int a, int b, int c, int d, int e) {x = a; y = b; dir = c; candy = d; com = e;}
};
int bfs(node);
int n, m, s;
int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};

int main()
{
    //freopen("output.txt", "w", stdout);
    while(cin >> n >> m >> s && (n || m || s))
    {
        node st;
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            cin >> mat[i];
            for(int j = 0; j < m && !flag; j++)
            {
                if(mat[i][j] == 'N' || mat[i][j] == 'S' || mat[i][j] == 'L' || mat[i][j] == 'O')
                {
                    st.x = i;
                    st.y = j;
                    if(mat[i][j] == 'N') st.dir = 0;
                    else if(mat[i][j] == 'L') st.dir = 1;
                    else if(mat[i][j] == 'S') st.dir = 2;
                    else if(mat[i][j] == 'O') st.dir = 3;
                    st.candy = 0;
                    st.com = 0;
                    flag = true;
                }
            }
        }
        cin >> command;
        cout << bfs(st) << endl;
    }
}

int bfs(node st)
{
    queue<node> q;
    q.push(st);
    while(!q.empty())
    {
        node top = q.front();
        q.pop();
        int ux = top.x, uy = top.y, udir = top.dir, ucandy = top.candy, ucom = top.com;
        if(ucom == s) return ucandy;
        if(command[ucom] == 'D')
            q.push(node(ux, uy, (udir + 1) % 4, ucandy, ucom + 1));
        else if(command[ucom] == 'E')
            q.push(node(ux, uy, (udir - 1 + 4) % 4, ucandy, ucom + 1));
        else
        {
            int vx = ux + dirx[udir];
            int vy = uy + diry[udir];
            if(vx >= 0 && vx < n && vy >= 0 && vy < m)
            {
                if(mat[vx][vy] == '#')
                    q.push(node(ux, uy, udir, ucandy, ucom + 1));
                else if(mat[vx][vy] == '.' || mat[vx][vy] == 'N' || mat[vx][vy] == 'S' || mat[vx][vy] == 'L' || mat[vx][vy] == 'O')
                    q.push(node(vx, vy, udir, ucandy, ucom + 1));
                else if(mat[vx][vy] == '*')
                {
                    mat[vx][vy] = '.';
                    q.push(node(vx, vy, udir, ucandy + 1, ucom + 1));
                }
            }
            else
                q.push(node(ux, uy, udir, ucandy, ucom + 1));
        }
    }
    return -1;
}
