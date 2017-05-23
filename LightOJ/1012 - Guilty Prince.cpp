#include<bits/stdc++.h>
#define MAX 25

using namespace std;

int row, col;
char mat[MAX][MAX];

int distX[] = {0, 0, -1, 1}, distY[] = {-1, 1, 0, 0};

struct Cell {
    int x, y;
    Cell() {}
    Cell(int a, int b) {x = a; y = b;}
} start;

int bfs();

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &col, &row);
        getchar();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                scanf("%c", &mat[i][j]);
                if(mat[i][j] == '@')
                    start = Cell(i, j);
            }
            getchar();
        }
        printf("Case %d: %d\n", ++caseno, bfs());
    }
    return 0;
}

int bfs() {
    bool vis[MAX][MAX] = {false};
    queue< Cell > q;
    vis[start.x][start.y] = true;
    q.push(start);
    int counter = 1;
    while(!q.empty()) {
        Cell top = q.front();
        q.pop();
        int ux = top.x, uy = top.y;
        for(int i = 0; i < 4; i++) {
            int vx = ux + distX[i], vy = uy + distY[i];
            if(vx >= 0 && vx < row && vy >= 0 && vy < col && !vis[vx][vy] && mat[vx][vy] != '#') {
                vis[vx][vy] = true;
                counter++;
                q.push(Cell(vx, vy));
            }
        }
    }
    return counter;
}
