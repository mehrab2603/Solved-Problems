#include <bits/stdc++.h>

using namespace std;
int isdivisible(long long, long long);
int n,k;
int arr[10000];
int dp[10000][101];
bool vis[10000][101];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        memset(vis, false, sizeof(vis));
        if(isdivisible(0, 0)) printf("Divisible\n");
        else printf("Not divisible\n");
    }
}

int isdivisible(long long i, long long sum)
{
    if(i == n)
    {
        if(sum % k == 0) return 1;
        else return 0;
    }
    if(vis[i][sum]) return dp[i][sum];
    int ret1, ret2;
    ret1 = isdivisible(i+1, ((sum % k) + (arr[i] % k)) % k);
    ret2 = isdivisible(i+1, (((sum % k) - (arr[i] % k)) + k) % k);
    dp[i][sum] = ret1|ret2;
    vis[i][sum] = true;
    return  dp[i][sum];
}
