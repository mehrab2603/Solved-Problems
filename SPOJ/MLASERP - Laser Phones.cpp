#include <bits/stdc++.h>
#define MAX 100

using namespace std;
int h, w;
string mat[MAX];
int mirrors[MAX][MAX][4];
struct node
{
    int x, y, mirrors, face;
    node() {}
    node(int a, int b) {x = a; y = b;}
    node(int a, int b, int c, int d) {x = a; y = b; face = c; mirrors = d;}
    bool operator < (const node& p) const {return mirrors > p.mirrors;}
};
vector<node> cow;
int dijkstra();
int dirx[] = {1, 0, -1, 0};
int diry[] = {0, -1, 0, 1};

int main()
{
    scanf("%d %d", &w, &h);
    for(int i = 0; i < h; i++)
    {
        cin >> mat[i];
        for(int j = 0; j < (int)mat[i].size(); j++)
            if(mat[i][j] == 'C')
                cow.push_back(node(i, j));
    }
    printf("%d\n", dijkstra());
    return 0;
}

int dijkstra()
{
    memset(mirrors, 63, sizeof mirrors);
    priority_queue<node> q;
    node start = cow[0], finish = cow[1];
    for(int i = 0; i < 4; i++)
    {
        mirrors[start.x][start.y][i] = 0;
        q.push(node(start.x, start.y, i, 0));
    }
    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        int ux = top.x, uy = top.y, uface = top.face, umirrors = top.mirrors;
        if(ux == finish.x && uy == finish.y) return umirrors;
        for(int i = 0; i < 4; i++)
        {
            int vx = ux + dirx[i];
            int vy = uy + diry[i];
            int vface = i, vmirrors;
            if(i == (uface + 2) % 4) continue;
            if(vx >= 0 && vx < h && vy >= 0 && vy < w && mat[vx][vy] != '*')
            {
                if(i == uface)
                    vmirrors = umirrors;
                else
                    vmirrors = umirrors + 1;
                if(vmirrors < mirrors[vx][vy][vface])
                {
                    mirrors[vx][vy][vface] = vmirrors;
                    q.push(node(vx, vy, vface, vmirrors));
                }
            }
        }
    }
    return -1;
}
