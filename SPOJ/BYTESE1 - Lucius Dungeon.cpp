#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
void dijkstra();
bool bcheck(int, int);
int mat[105][105];
int dist[105][105];
int dirx[] = {-1, 1, 0, 0};
int diry[] = {0, 0, 1, -1};
struct cell
{
    int x, y, w;
    cell(int a, int b, int c) {x = a; y = b; w = c;}
    bool operator < (const cell& p) const {return w > p.w;}
};
int m, n;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &m, &n);
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                int x;
                scanf("%d", &x);
                mat[i][j] = x;
            }
        }
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        dijkstra();
        if(dist[a][b] > t)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            printf("%d\n", t - dist[a][b]);
        }

    }
    return 0;
}

void dijkstra()
{
    memset(dist, 63, sizeof(dist));
    priority_queue<cell> q;
    dist[1][1] = mat[1][1];
    q.push(cell(1, 1, dist[1][1]));
    while(!q.empty())
    {
        cell top = q.top();
        q.pop();
        int ux = top.x;
        int uy = top.y;
        for(int i = 0; i < 4; i++)
        {
            int vx = top.x + dirx[i];
            int vy = top.y + diry[i];
            if(bcheck(vx, vy))
            {
                if(dist[ux][uy] + mat[vx][vy] < dist[vx][vy])
                {
                    dist[vx][vy] = dist[ux][uy] + mat[vx][vy];
                    q.push(cell(vx, vy, dist[vx][vy]));
                }
            }
        }

    }
}

bool bcheck(int x, int y)
{
    if(x >= 1 && x <= m && y >= 1 && y <= n)
        return true;
    else
        return false;
}
