#include <bits/stdc++.h>
#define MAX 30

using namespace std;
string mat[MAX];
int dist[MAX][MAX];
struct cell
{
    int x, y, dist;
    cell() {}
    cell(int a, int b) {x = a; y = b;}
    cell(int a, int b, int c) {x = a; y = b; dist = c;}
    bool operator < (const cell& p) const {return dist > p.dist;}
};
int dijkstra(cell, cell);
int dirx[] = {0, 0, -1, 1};
int diry[] = {-1, 1, 0, 0};
int c, r;

int main()
{
    while(scanf("%d %d", &c, &r) && c && r)
    {
        cell st, ed;
        for(int i = 0; i < r; i++)
        {
            cin >> mat[i];
            for(int j = 0; j < c; j++)
            {
                if(mat[i][j] == 'S')
                    st.x = i, st.y = j, st.dist = 0;
                else if(mat[i][j] == 'D')
                    ed.x = i, ed.y = j;
            }
        }
        printf("%d\n", dijkstra(st, ed));
        getchar();
    }
    return 0;
}

int dijkstra(cell start, cell dest)
{
    memset(dist, 63, sizeof dist);
    priority_queue<cell> q;
    dist[start.x][start.y] = 0;
    q.push(start);
    while(!q.empty())
    {
        cell top = q.top();
        q.pop();
        int ux = top.x, uy = top.y, udist = top.dist;
        if(ux == dest.x && uy == dest.y) return udist;
        for(int i = 0; i < 4; i++)
        {
            int vx = ux + dirx[i];
            int vy = uy + diry[i];
            if(vx >= 0 && vx < r && vy >= 0 && vy < c && mat[vx][vy] != 'X' && mat[vx][vy] != 'S')
            {
                int vcost;
                if(mat[ux][uy] == 'S' || mat[ux][uy] == 'D') vcost = 0;
                else vcost = mat[ux][uy] - '0';
                if(udist + vcost < dist[vx][vy])
                {
                    dist[vx][vy] = udist + vcost;
                    q.push(cell(vx, vy, dist[vx][vy]));
                }
            }
        }
    }
    return 0;
}
