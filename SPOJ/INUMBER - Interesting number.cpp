#include <bits/stdc++.h>
#define MAX 1001

using namespace std;
struct number
{
    int rem, sum;
    number() {}
    number(int rem, int sum) {this->rem = rem; this->sum = sum;}
};
void bfs(int);
void print(int, int);
short par[MAX][MAX], par2[MAX][MAX];
bool vis[MAX][MAX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        bfs(n);
        printf("\n");
    }
    return 0;
}

void bfs(int n)
{
    memset(vis, false, sizeof vis);
    queue<number> q;
    q.push(number(0, 0));
    while(!q.empty())
    {
        number top = q.front();
        q.pop();
        for(int i = 0; i < 10; i++)
        {
            int sum = top.sum + i;
            if(sum > n) break;
            int rem = (top.rem * 10 + i) % n;
            if(!vis[rem][sum])
            {
                vis[rem][sum] = true;
                par[rem][sum] = i;
                par2[rem][sum] = top.rem;
                q.push(number(rem, sum));
            }
            if(sum == n && rem == 0) {print(rem, sum); return;}
        }
    }
    return;
}

void print(int rem, int sum)
{
    if(rem == 0 && sum == 0) return;
    print(par2[rem][sum], sum - par[rem][sum]);
    printf("%d", par[rem][sum]);
}
