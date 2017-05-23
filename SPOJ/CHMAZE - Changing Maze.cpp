#include <bits/stdc++.h>

using namespace std;
bool tilecheck(int, int, int);
void bfs();
int m, n, o;
string mat[10][20];
int dist[20][20][10];
int dirx[] = {0, -1, 1, 0, 0};
int diry[] = {0, 0, 0, -1, 1};
struct tile { int x, y, maze; tile() {} tile(int a, int b, int c) {x = a; y = b; maze = c;} };

int main()
{
    int caseno = 0;
    while(scanf("%d %d %d", &m, &n, &o) && (m || n || o))
    {
        string s1;
        for(int i = 0; i < o; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> s1;
                mat[i][j] = s1;
            }
        }
        bfs();
        int mini = dist[m - 1][n - 1][0];
        for(int i = 1; i < 10; i++)
            if(dist[m - 1][n - 1][i] < mini)
                mini = dist[m - 1][n - 1][i];
        if(mini == 1061109567)
            printf("Case %d: Luke and Leia cannot escape.\n", ++caseno);
        else
            printf("Case %d: Luke and Leia can escape in %d steps.\n", ++caseno, mini);

    }
    return 0;
}

void bfs()
{
    memset(dist, 63, sizeof(dist));
    bool vis[20][20][10] = {false};
    vis[0][0][0] = true;
    dist[0][0][0] = 0;
    queue<tile> q;
    q.push(tile(0, 0, 0));
    while(!q.empty())
    {
        tile top = q.front();
        q.pop();
        int ux = top.x, uy = top.y, umaze = top.maze % o;
        if(ux == m - 1 && uy == n - 1) return;
        for(int i = 0; i < 5; i++)
        {
            int vx = ux + dirx[i];
            int vy = uy + diry[i];
            int vmaze = (umaze + 1) % o;
            if(!vis[vx][vy][vmaze] && tilecheck(vx, vy, vmaze))
            {
                dist[vx][vy][vmaze] = dist[ux][uy][umaze] + 1;
                vis[vx][vy][vmaze] = true;
                q.push(tile(vx, vy, vmaze));
            }
        }
    }
    return;
}

bool tilecheck(int x, int y, int maze)
{
    if(x >= 0 && x < m && y >= 0 && y < n && mat[maze][x][y] == '0')
        return true;
    else
        return false;
}
