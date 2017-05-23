#include <bits/stdc++.h>

using namespace std;

bool mat[1000][1000];
bool taken[1000][1000];
int dist[1000][1000];
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};
int row, col, startx, starty, endx, endy;
bool bombcheck(int, int);
void bfs();

struct Square
{
    int row, col;
};

int main()
{
    while(scanf("%d %d", &row, &col) && (row || col))
    {
        int brow;
        scanf("%d", &brow);
        memset(mat, false, sizeof(mat));
        for(int i = 0; i < brow; i++)
        {
            int currow, bcount;
            scanf("%d %d", &currow, &bcount);
            for(int j = 0; j < bcount; j++)
            {
                int curcol;
                scanf("%d", &curcol);
                mat[currow][curcol] = true;
            }
        }
        scanf("%d %d %d %d", &startx, &starty, &endx, &endy);
        memset(taken, false, sizeof(taken));
        memset(dist, 0, sizeof(dist));
        bfs();
        printf("%d\n", dist[endx][endy]);
    }
}

void bfs()
{
    queue<Square> q;
    Square source;
    source.row = startx;
    source.col = starty;
    dist[source.row][source.col] = 0;
    taken[source.row][source.col] = true;
    q.push(source);
    while(!q.empty())
    {
        Square u = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = u.row + dirx[i];
            int ny = u.col + diry[i];
            if(nx >= 0 && nx < row && ny >= 0 && ny < col && bombcheck(nx, ny) && !taken[nx][ny])
            {

                Square v;
                v.row = nx;
                v.col = ny;
                dist[nx][ny] = dist[u.row][u.col] + 1;
                taken[nx][ny] = true;
                q.push(v);
            }
        }
    }

}

bool bombcheck(int x, int y)
{
    if(mat[x][y] == true)
        return 0;
    else return 1;
}
