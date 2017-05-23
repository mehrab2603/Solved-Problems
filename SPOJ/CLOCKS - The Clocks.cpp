#include <bits/stdc++.h>

using namespace std;
void bfs();
int arr[9];
int mov[9][9] = { {1, 1, 0, 1, 1, 0, 0, 0, 0},
                  {1, 1, 1, 0, 0, 0, 0, 0, 0},
                  {0, 1, 1, 0, 1, 1, 0, 0, 0},
                  {1, 0, 0, 1, 0, 0, 1, 0, 0},
                  {0, 1, 0, 1, 1, 1, 0, 1, 0},
                  {0, 0, 1, 0, 0, 1, 0, 0, 1},
                  {0, 0, 0, 1, 1, 0, 1, 1, 0},
                  {0, 0, 0, 0, 0, 0, 1, 1, 1},
                  {0, 0, 0, 0, 1, 1, 0, 1, 1} };
int dist[4][4][4][4][4][4][4][4][4];
int input[9];
struct clocks
{
    int a, b, c, d, e, f, g, h, i;
    clocks() {}
    clocks(int a, int b, int c, int d, int e, int f, int g, int h, int i)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->e = e;
        this->f = f;
        this->g = g;
        this->h = h;
        this->i = i;
    }
};
clocks par[4][4][4][4][4][4][4][4][4];
int work[4][4][4][4][4][4][4][4][4];

int main()
{
    for(int i = 0; i < 9; i++)
        scanf("%d", &input[i]);
    bfs();
    return 0;
}

void bfs()
{
    memset(dist, 63, sizeof(dist));
    dist[input[0]][input[1]][input[2]][input[3]][input[4]][input[5]][input[6]][input[7]][input[8]] = 0;
    queue<clocks> q;
    q.push(clocks(input[0], input[1], input[2], input[3], input[4], input[5], input[6], input[7], input[8]));
    while(!q.empty())
    {
        clocks top = q.front();
        q.pop();
        if(top.a == 0 && top.b == 0 && top.c == 0 && top.d == 0 && top.e == 0 && top.f == 0 && top.g == 0 && top.h == 0 && top.i == 0)
        {
            vector<int> ans;
            clocks iter = top;
            while(dist[iter.a][iter.b][iter.c][iter.d][iter.e][iter.f][iter.g][iter.h][iter.i] != 0)
            {
                ans.push_back(work[iter.a][iter.b][iter.c][iter.d][iter.e][iter.f][iter.g][iter.h][iter.i]);
                iter = par[iter.a][iter.b][iter.c][iter.d][iter.e][iter.f][iter.g][iter.h][iter.i];
            }
            reverse(ans.begin(), ans.end());
            for(int i = 0; i < (int)ans.size() - 1; i++)
                printf("%d ", ans[i]);
            printf("%d\n", ans[ans.size() - 1]);
            return;
        }
        int tempdist = dist[top.a][top.b][top.c][top.d][top.e][top.f][top.g][top.h][top.i] + 1;
        for(int i = 0; i < 9; i++)
        {
            int va = (top.a + mov[i][0]) % 4;
            int vb = (top.b + mov[i][1]) % 4;
            int vc = (top.c + mov[i][2]) % 4;
            int vd = (top.d + mov[i][3]) % 4;
            int ve = (top.e + mov[i][4]) % 4;
            int vf = (top.f + mov[i][5]) % 4;
            int vg = (top.g + mov[i][6]) % 4;
            int vh = (top.h + mov[i][7]) % 4;
            int vi = (top.i + mov[i][8]) % 4;
            if(dist[va][vb][vc][vd][ve][vf][vg][vh][vi] > tempdist)
            {
                par[va][vb][vc][vd][ve][vf][vg][vh][vi] = top;
                dist[va][vb][vc][vd][ve][vf][vg][vh][vi] = tempdist;
                work[va][vb][vc][vd][ve][vf][vg][vh][vi] = i + 1;
                q.push(clocks(va, vb, vc, vd, ve, vf, vg, vh, vi));
            }
        }
    }
}
