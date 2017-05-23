#include<bits/stdc++.h>
#define MAX 15

using namespace std;

struct Node {
    int x, y, moves;
    Node() {}
    Node(int x, int y, int moves) {this->x = x; this->y = y; this->moves = moves;}
};

int m, n, moves[MAX][MAX], riders[MAX][MAX];
int dirX[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dirY[] = {2, -2, 1, -1, 2, -2, 1, -1};
bool vis[MAX][MAX];

void bfs(Node, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &m, &n);
        getchar();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                moves[i][j] = 0, riders[i][j] = 0;
        int riderCount = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                char ch;
                scanf("%c", &ch);
                if(ch != '.') bfs(Node(i, j, -1), ch - '0'), riderCount++;
            }
            getchar();
        }
        int ans = INT_MAX;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(riders[i][j] == riderCount)
                    ans = min(ans, moves[i][j]);
        if(ans == INT_MAX) ans = -1;
        printf("Case %d: %d\n", ++caseno, ans);
    }
    return 0;
}


void bfs(Node source, int type) {
    memset(vis, false, sizeof vis);
    queue< Node > q;
    vis[source.x][source.y] = true;
    riders[source.x][source.y]++;
    q.push(source);
    while(!q.empty()) {
        Node top = q.front();
        q.pop();
        int ux = top.x, uy = top.y, umoves = top.moves;
        for(int i = 0; i < 8; i++) {
            int vx = ux + dirX[i], vy = uy + dirY[i], vmoves = umoves + 1;
            if(vx >= 0 && vx < m && vy >= 0 && vy < n && !vis[vx][vy]) {
                vis[vx][vy] = true;
                riders[vx][vy]++;
                moves[vx][vy] += (vmoves / type) + 1;
                q.push(Node(vx, vy, vmoves));
            }
        }
    }
}
