#include <bits/stdc++.h>
#define MAX 110

using namespace std;
struct spark
{
    int x, y, s, number;
    double time;
    spark() {}
    spark(int x, int y, int s, int number) {this->x = x; this->y = y; this->s = s; this->number = number;}
    bool operator < (const spark& p) const {return time > p.time;}
};
vector<spark> sparks;
vector<int> adj[MAX];
double times[MAX];
void dijkstra();
int n;
double distCalc(int, int, int, int);

int main()
{
    scanf("%d", &n);
    sparks.push_back(spark());
    for(int i = 1; i <= n; i++)
    {
        int x, y, s;
        scanf("%d %d %d", &x, &y, &s);
        sparks.push_back(spark(x, y, s, i));
        for(int j = 0; j < n - 1; j++)
        {
            int a;
            scanf("%d", &a);
            adj[i].push_back(a);
        }
    }
    dijkstra();
    for(int i = 1; i <= n; i++)
        printf("%.6lf\n", times[i]);
    return 0;
}

void dijkstra()
{
    for(int i = 1; i <=n; i++) times[i] = 99999999.0;
    sparks[1].time = 0;
    times[1] = 0;
    priority_queue<spark> q;
    q.push(sparks[1]);
    while(!q.empty())
    {
        spark top = q.top();
        q.pop();
        int ux = top.x, uy = top.y, unumber = top.number, us = top.s;
        for(int i = 0; i < (int)adj[unumber].size() && us; i++)
        {
            int vnumber = adj[unumber][i], vx = sparks[vnumber].x, vy = sparks[vnumber].y;
            double reqTime = distCalc(ux, uy, vx, vy);
            if(times[vnumber] > times[unumber]) us--;
            if(times[unumber] + reqTime < times[vnumber])
            {
                times[vnumber] = times[unumber] + reqTime;
                sparks[vnumber].time = times[vnumber];
                q.push(sparks[vnumber]);
            }
        }
    }
}

double distCalc(int ux, int uy, int vx, int vy)
{
    int temp1 = (ux - vx) * (ux - vx);
    int temp2 = (uy - vy) * (uy - vy);
    return sqrt(temp1 + temp2);
}
