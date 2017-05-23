#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int editdistance(int, int);
char s1[2001];
char s2[2001];
int dp[2001][2001];
bool vis[2001][2001];
int size1, size2;
const int inf = 999999;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s %s", s1, s2);
        memset(vis, false, sizeof(vis));
        size1 = strlen(s1);
        size2 = strlen(s2);
        printf("%d\n", editdistance(0, 0));
    }
    return 0;
}

int editdistance(int i, int j)
{
    if(i == size1 && j < size2) return size2 - j;
    if(i < size1 && j == size2) return size1 - i;
    if(i == size1 && j == size2) return 0;
    if(vis[i][j] == true) return dp[i][j];
    int ret = inf;
    if(s1[i] == s2[j])
        ret = min(ret, editdistance(i + 1, j + 1));
    else
    {
        ret = min(ret, 1 + editdistance(i + 1, j));
        ret = min(ret, 1 + editdistance(i, j + 1));
        ret = min(ret, 1 + editdistance(i + 1, j + 1));
    }
    dp[i][j] = ret;
    vis[i][j] = true;
    return dp[i][j];
}
