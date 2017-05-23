#include <bits/stdc++.h>

using namespace std;

void bfs(int, int);
struct Square{int x, y;};
int dist[9][9];
bool vis[9][9];
int dirx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int diry[] = {-2, -1, 1, 2, -2, -1, 1, 2};


int main()
{
    char s1[3], s2[3];
    while(scanf("%s %s", s1, s2) != EOF)
    {
        int startx, starty, endx, endy;
        startx = s1[1] - '0';
        starty = s1[0] - 'a' + 1;
        endx = s2[1] - '0';
        endy = s2[0] - 'a' + 1;
        memset(vis, false, sizeof(vis));
        bfs(startx, starty);
        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, dist[endx][endy]);
    }
    return 0;
}

void bfs(int sx, int sy)
{
    queue<Square> q;
    Square src;
    src.x = sx;
    src.y = sy;
    dist[sx][sy] = 0;
    vis[sx][sy] = true;
    q.push(src);
    while(!q.empty())
    {
        Square u = q.front();
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            int nx = u.x + dirx[i];
            int ny = u.y + diry[i];
            if(nx > 0 && nx < 9 && ny > 0 && ny < 9 && !vis[nx][ny])
            {
                Square v;
                v.x = nx;
                v.y = ny;
                dist[v.x][v.y] = dist[u.x][u.y] + 1;
                vis[v.x][v.y] = true;
                q.push(v);
            }
        }
    }
}
