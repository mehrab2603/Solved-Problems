#include <bits/stdc++.h>

using namespace std;
vector<int> input;
int dp[1000][32768];
bool vis[1000][32768];
int func(int, int);

int main()
{
    //freopen("output.txt", "w", stdout);
    int caseno = 0;
    bool flag = false;
    while(1)
    {
        while(1)
        {
            int x;
            scanf("%d", &x);
            if(x == -1) break;
            input.push_back(x);
        }
        if(input.size() == 0) return 0;
        if(flag == false) flag = true;
        else printf("\n");
        input.push_back(-1);
        memset(vis, false, sizeof(vis));
        int answer = func(0, 999999);
        input.clear();
        printf("Test #%d:\n  maximum possible interceptions: %d\n",++caseno, answer);
    }
    return 0;
}

int func(int i, int num)
{
    if(input[i] == -1) return 0;
    if(vis[i][num] == true) return dp[i][num];
    int ret1 = -999, ret2 = -999;
    if(input[i] <= num) ret1 = 1 + func(i + 1, input[i]);
    ret2 = func(i + 1, num);
    dp[i][num] = max(ret1, ret2);
    vis[i][num] = true;
    return dp[i][num];
}
