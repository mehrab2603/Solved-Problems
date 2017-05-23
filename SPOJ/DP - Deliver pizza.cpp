#include <bits/stdc++.h>
#define inf 1061109567

using namespace std;
string input[50];
int m, n;
struct square
{
    int x, y, dist;
    square() {}
    square(int a, int b) {x = a; y = b;}
    square(int a, int b, int c) {x = a; y = b; dist = c;}
    bool operator < (const square& p) const {return dist > p.dist;}
};
vector<square> buildings;
vector<int> bdistance;
int dirx[] = {-1, 1, 0, 0};
int diry[] = {0, 0, -1, 1};
int dijkstra(square, square);
int answer;
bool taken[20] = {false};
void mintime(int);

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        square start(-1, -1);
        scanf("%d %d", &m, &n);
        getchar();
        for(int i = 0; i < m; i++)
        {
            cin >> input[i];
            for(int j = 0; j < (int)input[i].length(); j++)
            {
                if(input[i][j] == '$')
                    buildings.push_back(square(i, j));
                else if(input[i][j] == 'X')
                    start.x = i, start.y = j;
            }
        }
        if(buildings.size() == 0)
        {
            printf("0\n");
            buildings.clear();
            bdistance.clear();
            continue;
        }
        else if(start.x == -1)
        {
            printf("-1\n");
            buildings.clear();
            bdistance.clear();
            continue;
        }
        bool flag = false;
        for(int i = 0; i < (int)buildings.size(); i++)
        {
            int dist = dijkstra(start, buildings[i]);
            if(dist == -1)
            {
                printf("-1\n");
                buildings.clear();
                bdistance.clear();
                flag = true;
                break;
            }
            else
                bdistance.push_back(dist);
        }
        if(flag == true) continue;
        if(bdistance.size() == 1)
            printf("%d\n",bdistance[0]);
        else
        {
            sort(bdistance.begin(), bdistance.end());
            answer = inf;
            mintime(0);
            printf("%d\n", answer);
        }
        buildings.clear();
        bdistance.clear();
    }
}

int dijkstra(square start, square dest)
{
    int dist[50][50];
    memset(dist, 63, sizeof(dist));
    priority_queue<square> q;
    dist[start.x][start.y] = 0;
    start.dist = 0;
    q.push(start);
    while(!q.empty())
    {
        square top = q.top();
        q.pop();
        int ux = top.x;
        int uy = top.y;
        int udist = top.dist;
        if(ux == dest.x && uy == dest.y)
            return dist[ux][uy];
        for(int i = 0; i < 4; i++)
        {
            int vx = ux + dirx[i];
            int vy = uy + diry[i];
            int vcost;
            if(vx >= 0 && vx < m && vy >= 0 && vy < n)
            {
                if(input[vx][vy] == '$' || input[ux][uy] == '$' || input[ux][uy] == 'X' || input[vx][vy] == 'X')
                    vcost = 2;
                else
                {
                    int uheight = input[ux][uy] - '0';
                    int vheight = input[vx][vy] - '0';
                    int dif = uheight - vheight;
                    if(dif < 0) dif *= -1;
                    if(dif == 1)
                        vcost = 3;
                    else if(dif == 0)
                        vcost = 1;
                    else
                        vcost = inf;
                }
                if(udist + vcost < dist[vx][vy])
                {
                    dist[vx][vy] = udist + vcost;
                    q.push(square(vx, vy, dist[vx][vy]));
                }
            }
        }
    }
    return -1;
}

void mintime(int i)
{
    if(i == (int)bdistance.size())
    {
        int time1 = 0, time2 = 0, max1 = -1, max2 = -1;
        for(int j = 0; j < (int)bdistance.size(); j++)
        {
            if(taken[j])
            {
                time1 += 2 * bdistance[j];
                max1 = j;
            }
            else
            {
                time2 += 2 * bdistance[j];
                max2 = j;
            }
        }
        if(max1 != -1) time1 -= bdistance[max1];
        if(max2 != -1) time2 -= bdistance[max2];
        int ans = max(time1, time2);
        if(ans < answer) answer = ans;
        return;
    }
    mintime(i + 1);
    taken[i] = true;
    mintime(i + 1);
    taken[i] = false;
}
