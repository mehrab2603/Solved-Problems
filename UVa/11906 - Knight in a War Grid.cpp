#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
    Node(int x, int y) {
        this->x = x;
        this->y = y;
    }
    bool operator<(const Node& n) const {
        if(this->x == n.x)
            return this->y < n.y;
        return this->x < n.x;
    }
};

const int MAX = 110;

int r, c, m, n;
int dirX[2], dirY[2];
bool grid[MAX][MAX];
bool vis[MAX][MAX];
int k[MAX][MAX];

void bfs();

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        memset(grid, false, sizeof grid);
        scanf("%d %d %d %d", &r, &c, &m, &n);
        dirX[0] = -m;
        dirX[1] = m;
        dirY[0] = -n;
        dirY[1] = n;
        int w;
        scanf("%d", &w);
        for(int i = 0; i < w; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            grid[y][x] = true;
        }
        bfs();
        int even = 0, odd = 0;
        for(int i = 0; i < c; i++) {
            for(int j = 0; j < r; j++) {
                if(vis[i][j]) {
                    if(k[i][j] % 2 == 0) even++;
                    else odd++;
                }
            }
        }
        printf("Case %d: %d %d\n", ++caseno, even, odd);
    }
    return 0;
}

void bfs() {
    memset(vis, false, sizeof vis);
    memset(k, 0, sizeof k);
    queue< Node > q;
    q.push(Node(0, 0));
    vis[0][0] = true;
    while(!q.empty()) {
        Node top = q.front();
        q.pop();
        int ux = top.x, uy = top.y;
        set< Node > temp;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                int vx1 = ux + dirX[i], vy1 = uy + dirY[j];
                int vx2 = ux + dirY[j], vy2 = uy + dirX[i];
                if(vx1 >= 0 && vx1 < c && vy1 >= 0 && vy1 < r && !grid[vx1][vy1]) {
                    temp.insert(Node(vx1, vy1));
                    if(!vis[vx1][vy1]) {
                        vis[vx1][vy1] = true;
                        q.push(Node(vx1, vy1));
                    }
                }
                if(vx2 >= 0 && vx2 < c && vy2 >= 0 && vy2 < r && !grid[vx2][vy2]) {
                    temp.insert(Node(vx2, vy2));
                    if(!vis[vx2][vy2]) {
                        vis[vx2][vy2] = true;
                        q.push(Node(vx2, vy2));
                    }
                }
            }
        }
        k[ux][uy] += temp.size();
    }
}
