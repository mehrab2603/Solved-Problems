#include <bits/stdc++.h>
#define MAX 55

using namespace std;


void trans(int, int);
int m, n, mat[MAX][MAX], mat2[MAX][MAX];
struct square{int x, y, dir; square() {} square(int a, int b) {x = a; y = b;} square(int a, int b, int c) {x = a; y = b; dir = c;}};
map<string, int> mymap;
int bfs(square, square);
int dirx[] = {1, 0, -1, 0};
int diry[] = {0, -1, 0, 1};
int face[] = {0, 1, 2, 3};
bool vis2[MAX][MAX];

int main()
{
    mymap["south"] = 0;
    mymap["west"] = 1;
    mymap["north"] = 2;
    mymap["east"] = 3;
    while(scanf("%d %d", &m, &n) && (m || n))
    {
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &mat2[i][j]);
        memset(vis2, false, sizeof(vis2));
        memset(mat, 0, sizeof(mat));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(!vis2[i][j]) trans(i, j);
        int b1, b2, e1, e2;
        string dir;
        cin >> b1 >> b2 >> e1 >> e2 >> dir;
        square start(b1, b2, mymap[dir]), dest(e1, e2);
        int result = bfs(start, dest);
        if(result != -1) printf("%d\n", result);
        else printf("-1\n");
    }
    return 0;
}

int bfs(square start, square dest)
{
    int dist[MAX][MAX][4];
    bool vis[MAX][MAX][4];
    memset(vis, false, sizeof(vis));
    queue<square> q;
    dist[start.x][start.y][start.dir] = 0;
    vis[start.x][start.y][start.dir] = true;
    q.push(start);
    while(!q.empty())
    {
        square top = q.front();
        q.pop();
        int ux = top.x, uy = top.y, udir = top.dir;
        if(ux == dest.x && uy == dest.y)
                return dist[ux][uy][udir];
        for(int i = 0; i < 5; i++)
        {
            int vx, vy, vdir;
            if(i == 0)
            {
                vx = ux + dirx[udir];
                vy = uy + diry[udir];
                vdir = udir;
            }
            else if(i == 1)
            {
                vx = ux;
                vy = uy;
                vdir = (udir + 1 + 4) % 4;
            }
            else if(i == 2)
            {
                vx = ux;
                vy = uy;
                vdir = (udir - 1 + 4) % 4;
            }
            else if(i == 3)
            {
                int tempx = ux + dirx[udir];
                int tempy = uy + diry[udir];
                if(tempx > 0 && tempx < m && tempy > 0 && tempy < n && mat[tempx][tempy] != 1)
                {
                    vx = tempx + dirx[udir];
                    vy = tempy + diry[udir];
                    vdir = udir;
                }
                else continue;
            }
            else if(i == 4)
            {
                int tempx = ux + dirx[udir];
                int tempy = uy + diry[udir];
                if(tempx > 0 && tempx < m && tempy > 0 && tempy < n && mat[tempx][tempy] != 1)
                {
                    tempx = tempx + dirx[udir];
                    tempy = tempy + diry[udir];
                    if(tempx > 0 && tempx < m && tempy > 0 && tempy < n && mat[tempx][tempy] != 1)
                    {
                        vx = tempx + dirx[udir];
                        vy = tempy + diry[udir];
                        vdir = udir;
                    }
                    else continue;
                }
                else continue;
            }
            if(vx > 0 && vx < m && vy > 0 && vy < n && mat[vx][vy] != 1 && !vis[vx][vy][vdir])
            {
                vis[vx][vy][vdir] = true;
                dist[vx][vy][vdir] = dist[ux][uy][udir] + 1;
                q.push(square(vx, vy, vdir));
            }
        }
    }
    return -1;
}

void trans(int i, int j)
{
    vis2[i][j] = true;
    if(mat2[i][j])
    {
        mat[i][j] = 1;
        if(i + 1 <= m) {mat[i + 1][j] = 1; if(mat2[i + 1][j] == 0) vis2[i + 1][j] = true;}
        if(j + 1 <= n) {mat[i][j + 1] = 1; if(mat2[i][j + 1] == 0) vis2[i][j + 1] = true;}
        if(i + 1 <= m && j + 1 <= n) {mat[i + 1][j + 1] = 1; if(mat2[i + 1][j + 1] == 0) vis2[i + 1][j + 1] = true;}
    }
    else
        mat[i][j] = 0;
}

