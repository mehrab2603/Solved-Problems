#include <bits/stdc++.h>
#define MAX 1000

using namespace std;
int dirx[] = {0, 0, -1, 1};
int diry[] = {-1, 1, 0, 0};
int r, c;
struct square
{
    int x, y; square() {} square(int a, int b) {x = a; y = b;}
};
string mat[MAX];
vector<square> fire;
int ft[MAX][MAX];
void ftcalc();
int bfs(square);

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        square start;
        scanf("%d %d", &r, &c);
        for(int i = 0; i < r; i++)
        {
            cin >> mat[i];
            for(int j = 0; j < (int)mat[i].length(); j++)
            {
                if(mat[i][j] == 'J')
                {
                    start.x = i;
                    start.y = j;
                }
                else if(mat[i][j] == 'F')
                    fire.push_back(square(i, j));
            }
        }
        ftcalc();
        int result = bfs(start);
        if(result == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", result + 1);
        fire.clear();
    }

}

int bfs(square start)
{
    int dist[MAX][MAX];
    bool vis[MAX][MAX];
    memset(vis, false, sizeof(vis));
    queue<square> q;
    dist[start.x][start.y] = 0;
    vis[start.x][start.y] = true;
    q.push(start);
    while(!q.empty())
    {
        square top = q.front();
        q.pop();
        int ux = top.x, uy = top.y;
        if(ux == 0 || ux == r - 1 || uy == 0 || uy == c - 1)
            return dist[ux][uy];
        for(int i = 0; i < 4; i++)
        {
            int vx = ux + dirx[i];
            int vy = uy + diry[i];
            if(vx >= 0 && vx < r && vy >= 0 && vy < c && mat[vx][vy] != '#' && !vis[vx][vy] && dist[ux][uy] + 1 < ft[vx][vy])
            {
                vis[vx][vy] = true;
                dist[vx][vy] = dist[ux][uy] + 1;
                q.push(square(vx, vy));
            }
        }
    }
    return -1;
}

void ftcalc()
{
    //int dist[MAX][MAX];
    bool vis[MAX][MAX];
    memset(vis, false, sizeof(vis));
    memset(ft, 63, sizeof ft);
    queue<square> q;
    for(int i = 0; i < (int)fire.size(); i++)
    {
        square source = fire[i];
        ft[source.x][source.y] = 0;
        vis[source.x][source.y] = true;
        q.push(source);
    }
    while(!q.empty())
    {
        square top = q.front();
        q.pop();
        int ux = top.x, uy = top.y;
        for(int i = 0; i < 4; i++)
        {
            int vx = ux + dirx[i];
            int vy = uy + diry[i];
            if(vx >= 0 && vx < r && vy >= 0 && vy < c && !vis[vx][vy] && mat[vx][vy] != '#')
            {
                ft[vx][vy] = ft[ux][uy] + 1;
                vis[vx][vy] = true;
                q.push(square(vx, vy));
            }
        }
    }

}
