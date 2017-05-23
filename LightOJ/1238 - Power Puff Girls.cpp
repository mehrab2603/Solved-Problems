#include <bits/stdc++.h>
#define MAX 25

using namespace std;

struct Cell {
    int x, y, dist;
    Cell() {}
    Cell(int x, int y, int dist) {this->x = x; this->y = y; this->dist = dist;}
};
int m, n;
vector< Cell > start;
char mat[MAX][MAX];
int dirX[] = {-1, 0, 0, 1};
int dirY[] = {0, -1, 1, 0};
bool vis[MAX][MAX];

int bfs(Cell);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        start.clear();
        scanf("%d %d", &m, &n);
        getchar();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                char ch;
                scanf("%c", &ch);
                if(ch == 'a' || ch == 'b' || ch == 'c') {
                    start.push_back(Cell(i, j, 0));
                    mat[i][j] = '.';
                }
                else if(ch == 'm') mat[i][j] = '#';
                else mat[i][j] = ch;
            }
            getchar();
        }
        int ans = -1;
        for(int i = 0; i < (int)start.size(); i++)
            ans = max(ans, bfs(start[i]));
        printf("Case %d: %d\n", ++caseno, ans);
    }
    return 0;
}

int bfs(Cell source) {
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            vis[i][j] = false;
    queue< Cell > q;
    vis[source.x][source.y] = true;
    q.push(source);
    while(!q.empty()) {
        Cell top = q.front();
        q.pop();
        int ux = top.x, uy = top.y, udist = top.dist;
        for(int i = 0; i < 4; i++) {
            int vx = ux + dirX[i], vy = uy + dirY[i], vdist = udist + 1;
            if(vx >= 0 && vx < m && vy >= 0 && vy < n && !vis[vx][vy] && mat[vx][vy] != '#') {
                vis[vx][vy] = true;
                if(mat[vx][vy] == 'h') return vdist;
                q.push(Cell(vx, vy, vdist));
            }
        }
    }
    return -1;
}
