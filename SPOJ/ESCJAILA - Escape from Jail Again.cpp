#include <bits/stdc++.h>

using namespace std;
int n, m;
string input[100];
struct cell
{
    int x, y;
    bool button;
    cell() {}
    cell(int a, int b) {x = a; y = b;}
    cell(int a, int b, bool c) {x = a; y = b; button = c;}
};
int bfs(cell);
int dirx[] = {0, 0, -1, 1};
int diry[] = {-1, 1, 0, 0};

int main()
{
    while(scanf("%d %d", &n, &m))
    {
        if(n == -1 && m == -1) break;
        cell start(-1, -1);
        for(int i = 0; i < n; i++)
        {
            cin >> input[i];
            for(int j = 0; j < (int)input[i].size(); j++)
                if(input[i][j] == 'H')
                    start.x = i, start.y = j;
        }
        int result = bfs(start);
        if(result == -1)
            printf("-1\n");
        else
            printf("%d\n", result + 1);
    }

}

int bfs(cell start)
{
    int dist[100][100][2];
    bool vis[100][100][2];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < 2; k++)
                vis[i][j][k] = false;
    queue<cell> q;
    dist[start.x][start.y][false] = 0;
    vis[start.x][start.y][false] = true;
    q.push(cell(start.x, start.y, false));
    while(!q.empty())
    {
        cell top = q.front();
        q.pop();
        int ux = top.x;
        int uy = top.y;
        bool ubutton = top.button;
        if(ux == 0 || ux == n - 1 || uy == 0 || uy == m - 1)
            return dist[ux][uy][ubutton];
        for(int i = 0; i < 4; i++)
        {
            int vx = ux + dirx[i];
            int vy = uy + diry[i];
            bool vbutton;
            if(vx >= 0 && vx < n && vy >= 0 && vy < m && input[vx][vy] != 'W')
            {
                if(input[vx][vy] == 'O')
                    vbutton = true;
                else if(input[vx][vy] == 'C')
                    vbutton = false;
                else
                    vbutton = ubutton;
                if(ubutton == false && input[vx][vy] == 'D') continue;
                else if(!vis[vx][vy][vbutton])
                {
                    dist[vx][vy][vbutton] = dist[ux][uy][ubutton] + 1;
                    vis[vx][vy][vbutton] = true;
                    q.push(cell(vx, vy, vbutton));
                }
            }
        }
    }
    return -1;
}
