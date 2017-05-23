#include <bits/stdc++.h>

using namespace std;

struct conf
{
    int a, b, c, d;
    conf() {}
    conf(int a1, int b1, int c1, int d1) {a = a1; b = b1; c = c1; d = d1;}
};
int bfs(conf, conf);
bool forbidden[10][10][10][10];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int sa, sb, sc, sd, fa, fb, fc, fd;
        scanf("%d %d %d %d %d %d %d %d", &sa, &sb, &sc, &sd, &fa, &fb, &fc, &fd);
        conf start(sa, sb, sc, sd), finish(fa, fb, fc, fd);
        int n;
        scanf("%d", &n);
        memset(forbidden, false, sizeof(forbidden));
        for(int i = 0; i < n; i++)
        {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            forbidden[a][b][c][d] = true;
        }
        int result = bfs(start, finish);
        printf("%d\n", result);

    }
    return 0;
}

int bfs(conf start, conf fin)
{
    int dist[10][10][10][10];
    queue<conf> q;
    dist[start.a][start.b][start.c][start.d] = 0;
    forbidden[start.a][start.b][start.c][start.d] = true;
    q.push(start);
    while(!q.empty())
    {
        conf top = q.front();
        q.pop();
        int ua = top.a, ub = top.b, uc = top.c, ud = top.d;
        if(ua == fin.a && ub == fin.b && uc == fin.c && ud == fin.d)
            return dist[ua][ub][uc][ud];
        for(int i = 0; i < 8; i++)
        {
            int va, vb, vc, vd;
            if(i == 0)
                va = (ua + 1) % 10, vb = ub, vc = uc, vd = ud;
            else if(i == 1)
                va = (ua - 1 + 10) % 10, vb = ub, vc = uc, vd = ud;
            else if(i == 2)
                va = ua, vb = (ub + 1) % 10, vc = uc, vd = ud;
            else if(i == 3)
                va = ua, vb = (ub - 1 + 10) % 10, vc = uc, vd = ud;
            else if(i == 4)
                va = ua, vb = ub, vc = (uc + 1) % 10, vd = ud;
            else if(i == 5)
                va = ua, vb = ub, vc = (uc - 1 + 10) %10, vd = ud;
            else if(i == 6)
                va = ua, vb = ub, vc = uc, vd = (ud + 1) % 10;
            else if(i == 7)
                va = ua, vb = ub, vc = uc, vd = (ud - 1 + 10) % 10;
            if(!forbidden[va][vb][vc][vd])
            {
                forbidden[va][vb][vc][vd] = true;
                dist[va][vb][vc][vd] = dist[ua][ub][uc][ud] + 1;
                q.push(conf(va, vb, vc, vd));
            }
        }
    }
    return -1;
}
