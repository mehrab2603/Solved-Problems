#include <bits/stdc++.h>
#define MAX 50

using namespace std;
int n, p1, p2, p3;
char mat[MAX][MAX];
struct location
{
    int pos1, pos2, pos3, dist;
    location() {}
    location(int a, int b, int c, int d) {pos1 = a; pos2 = b; pos3 = c; dist = d;}
};
int bfs();
bool vis[MAX][MAX][MAX];

int main()
{
    while(scanf("%d", &n) && n)
    {
        char s[3];
        scanf("%d %d %d", &p1, &p2, &p3);
        p1--, p2--, p3--;
        getchar();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                scanf("%s", s);
                mat[i][j] = s[0];
            }
        int result = bfs();
        if(result == -1)
            printf("impossible\n");
        else
            printf("%d\n", result);
    }
    return 0;
}

int bfs()
{
    if(p1 == p2 && p2 == p3)
        return 0;
    queue<location> q;
    memset(vis, false, sizeof(vis));
    vis[p1][p2][p3] = true;
    q.push(location(p1, p2, p3, 0));
    while(!q.empty())
    {
        location top = q.front();
        q.pop();
        int a = top.pos1, b = top.pos2, c = top.pos3, dist = top.dist;
        char col1 = mat[b][c];
        for(int i = 0; i < n; i++)
        {
            if(mat[a][i] == col1 && !vis[i][b][c])
            {
                if(i == b && b == c)
                    return dist + 1;
                vis[i][b][c] = true;
                q.push(location(i, b, c, dist + 1));
            }
        }
        char col2 = mat[a][c];
        for(int i = 0; i < n; i++)
        {
            if(mat[b][i] == col2 && !vis[a][i][c])
            {
                if(a == i && i == c)
                    return dist + 1;
                vis[a][i][c] = true;
                q.push(location(a, i, c, dist + 1));
            }
        }
        char col3 = mat[a][b];
        for(int i = 0; i < n; i++)
        {
            if(mat[c][i] == col3 && !vis[a][b][i])
            {
                if(a == b && b == i)
                    return dist + 1;
                vis[a][b][i] = true;
                q.push(location(a, b, i, dist + 1));
            }
        }
    }
    return -1;
}
