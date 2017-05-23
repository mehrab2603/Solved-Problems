#include <bits/stdc++.h>
#define MAX 30

using namespace std;
int l, r, c;
string mat[MAX][MAX];
struct square
{
    int x, y, z;
    square() {}
    square(int a, int b, int c) {x = a; y = b; z = c;}
};
int bfs(square, square);
int dirx[] = {0, 0, -1, 1, 0, 0};
int diry[] = {-1, 1, 0, 0, 0, 0};
int dirz[] = {0, 0, 0, 0, -1, 1};

int main()
{
    while(scanf("%d %d %d", &l, &r, &c) && (l || r || c))
    {
        square start, finish;
        for(int i = 0; i < l; i++)
        {
            for(int j = 0; j < r; j++)
            {
                cin >> mat[i][j];
                for(int k = 0; k < (int)mat[i][j].size(); k++)
                {
                    if(mat[i][j][k] == 'S')
                        start.x = j, start.y = k, start.z = i;
                    else if(mat[i][j][k] == 'E')
                        finish.x = j, finish.y = k, finish.z = i;
                }
            }
        }
        int ans = bfs(start, finish);
        if(ans == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", ans);
    }
    return 0;
}

int bfs(square start, square finish)
{
    int dist[MAX][MAX][MAX];
    bool vis[MAX][MAX][MAX];
    memset(vis, false, sizeof(vis));
    queue<square> q;
    vis[start.x][start.y][start.z] = true;
    dist[start.x][start.y][start.z] = 0;
    q.push(start);
    while(!q.empty())
    {
        square top = q.front();
        q.pop();
        int ux = top.x, uy = top.y, uz = top.z;
        if(ux == finish.x && uy == finish.y && uz == finish.z)
            return dist[ux][uy][uz];
        for(int i = 0; i < 6; i++)
        {
            int vx = ux + dirx[i];
            int vy = uy + diry[i];
            int vz = uz + dirz[i];
            if(vx >= 0 && vx < r && vy >= 0 && vy < c && vz >= 0 && vz < l && mat[vz][vx][vy] != '#' && !vis[vx][vy][vz])
            {
                vis[vx][vy][vz] = true;
                dist[vx][vy][vz] = dist[ux][uy][uz] + 1;
                q.push(square(vx, vy, vz));
            }
        }
    }
    return -1;
}
