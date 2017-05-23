#include <bits/stdc++.h>
#define MAX 110

using namespace std;
int n, m;
char mat[MAX][MAX];
int dist[MAX][MAX];
struct node
{
    int x, y, mask;
    node() {}
    node(int a, int b, int c) {x = a; y = b; mask = c;}

};
int dirX[] = {0, -1, 0, 1};
int dirY[] = {-1, 0, 1, 0};
int ans;
int setBit(int, int);
bool checkBit(int, int);
int bfs(node);
map <int, map <int, map<int, bool > > > vis;

int main()
{
    //freopen("input.txt", "r", stdin);
    while(scanf("%d", &n) != EOF)
    {
        getchar();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%c", &mat[i][j]);
            }
            getchar();
        }
        ans = bfs(node(0, 0, 0));
        printf("%d\n", ans);
    }
    return 0;
}

int setBit(int mask, int pos) {mask = mask | (1 << pos); return mask;}
bool checkBit(int mask, int pos) {return (bool)(mask & (1 << pos));}

int bfs(node src)
{
    vis.clear();
    dist[src.x][src.y] = 1;
    if(islower(mat[src.x][src.y])) src.mask = setBit(0, 10 + mat[src.x][src.y] - 'a');
    else src.mask = setBit(0, mat[src.x][src.y] - 'A');
    vis[src.mask][src.x][src.y] = true;
    queue <node> q;
    q.push(src);
    while(!q.empty())
    {
        node top = q.front();
        q.pop();
        int ux = top.x, uy = top.y;
        int umask = top.mask;
        for(int i = 0; i < 4; i++)
        {
            int vx = ux + dirX[i];
            int vy = uy + dirY[i];
            if(vx >= 0 && vx < n && vy >= 0 && vy < n)
            {
                int vpos, vmask;
                if(islower(mat[vx][vy])) vpos = mat[vx][vy] - 'a';
                else vpos = 10 + mat[vx][vy] - 'A';
                if(islower(mat[vx][vy])) vmask = setBit(umask, 10 + mat[vx][vy] - 'a');
                else vmask = setBit(umask, mat[vx][vy] - 'A');
                if(!checkBit(umask, vpos) && !vis[vmask][vx][vy])
                {
                    vis[vmask][vx][vy] = true;
                    dist[vx][vy] = dist[ux][uy] + 1;
                    if(vx == n - 1 && vy == n - 1)
                        return dist[vx][vy];
                    q.push(node(vx, vy, vmask));
                }
            }
        }
    }
    return -1;
}
