#include <bits/stdc++.h>

using namespace std;
int bfs();
string input;
bool vis[2500][2500];
struct point
{
    int x, y;
    point(int a, int b) {x = a; y = b;}
};

int main()
{

    while(cin >> input && input != "Q")
    {
        int ans = bfs();
        printf("%d\n", ans);

    }
    return 0;
}

int bfs()
{
    int counter = 0;
    memset(vis, false, sizeof(vis));
    queue<point> q;
    q.push(point(1100, 1100));
    for(int i = 0; i < input.size(); i++)
    {
        point x = q.front();
        q.pop();
        if(vis[x.x][x.y]) counter++;
        vis[x.x][x.y] = true;
        if(input[i] == 'U')
        {
            q.push(point(x.x, x.y + 1));
        }
        else if(input[i] == 'D')
        {
            q.push(point(x.x, x.y - 1));
        }
        else if(input[i] == 'L')
        {
            q.push(point(x.x - 1, x.y));
        }
        else if(input[i] == 'R')
        {
            q.push(point(x.x + 1, x.y));
        }
    }
    return counter;
}
