#include <bits/stdc++.h>
#define MAX 510

using namespace std;

int n, k;
int arr[MAX];
int dp[MAX][MAX];
bool vis[MAX][MAX];
int func(int, int);

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    memset(vis, false, sizeof vis);
    printf("%d\n", func(0, 0));
    return 0;
}

int func(int stable, int index)
{
    if(index == n && stable != k) return 9999999;
    if(index != n && stable == k) return 9999999;
    if(index == n && stable == k) return 0;
    if(vis[stable][index]) return dp[stable][index];
    int black = 0, white = 0, uFact, result = 9999999;
    for(int i = index; i < n; i++)
    {
        if(arr[i] == 1) black++;
        else white++;
        uFact = black * white;
        int uFact2 = func(stable + 1, i + 1);
        result = min(result, uFact + uFact2);
    }
    vis[stable][index] = true;
    dp[stable][index] = result;
    return result;
}
