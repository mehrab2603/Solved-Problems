#include <bits/stdc++.h>
#define MAX 25

using namespace std;
int n;
string mat[MAX], mat2[MAX];
int dirx[] = {0, 0, -1, 1, 0};
int diry[] = {-1, 1, 0, 0, 0};
struct cell
{
    int x, y, state;
    cell() {}
    cell(int a, int b) {x = a; y = b;}
    cell(int a, int b, int c) {x = a; y = b; state = c;}
};
int bfs();

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            cin >> mat[i];
        for(int i = 0; i < n; i++)
            cin >> mat2[i];
        int result = bfs();
        if(result == -1)
            printf("NO\n");
        else
            printf("%d\n", result);

    }
    return 0;
}

int bfs()
{
    int dist[MAX][MAX][10];
    bool vis[MAX][MAX][10];
    memset(vis, false, sizeof(vis));
    queue<cell> q;
    dist[0][0][0] = 0;
    vis[0][0][0] = true;
    q.push(cell(0, 0, 0));
    while(!q.empty())
    {
        cell top = q.front();
        q.pop();
        int ux = top.x, uy = top.y, ustate = top.state;
        int utime = dist[ux][uy][ustate];
        for(int i = 0; i < 5; i++)
        {
            int vx = ux + dirx[i];
            int vy = uy + diry[i];
            int vtime = utime + 1;
            int vstate = vtime % 10;
            char vcell;
            if(vx >= 0 && vx < n && vy >= 0 && vy < n)
            {
                int vperiod = mat2[vx][vy] - '0';
                if(vperiod != 0)
                {
                    if((vtime / vperiod) % 2 == 0) vcell = mat[vx][vy];
                    else vcell = (mat[vx][vy] == '.' ? '*' : '.');
                }
                else
                    vcell = mat[vx][vy];
                if(vcell != '*' && !vis[vx][vy][vstate])
                {
                    vis[vx][vy][vstate] = true;
                    dist[vx][vy][vstate] = vtime;
                    if(vx == n - 1 && vy == n - 1) return vtime;
                    q.push(cell(vx, vy, vstate));
                }
            }
        }
    }
    return -1;
}
