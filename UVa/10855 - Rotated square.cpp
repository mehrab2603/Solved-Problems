#include <bits/stdc++.h>
#define MAX 101

using namespace std;
int N, n;
void stringRotator();
int matchFinder();
char s1[MAX][MAX], s2[MAX][MAX];

int main()
{
    //freopen("input.txt", "r", stdin);
    while(scanf("%d %d", &N, &n) && (N || n))
    {
        getchar();
        for(int i = 0; i < N; i++)
        {

            for(int j = 0; j < N; j++)
                scanf("%c", &s1[i][j]);
            getchar();
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                scanf("%c", &s2[i][j]);
            getchar();
        }
        int ans1 = matchFinder();
        stringRotator();
        int ans2 = matchFinder();
        stringRotator();
        int ans3 = matchFinder();
        stringRotator();
        int ans4 = matchFinder();
        printf("%d %d %d %d\n", ans1, ans2, ans3, ans4);


    }
    return 0;
}

void stringRotator()
{
    char temp[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            temp[i][j] = s2[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            s2[i][j] = temp[n - j - 1][i];
}

int matchFinder()
{
    int ans = 0;
    for(int i = 0; i <= N - n; i++)
    {
        for(int j = 0; j <= N - n; j++)
        {
            bool flag = false;
            int match = 0;
            for(int k = 0; k < n; k++)
            {
                for(int l = 0; l < n; l++)
                {
                    if(s1[i + k][j + l] == s2[k][l]) match++;
                    else {flag = true; break;}
                }
                if(match == n * n) ans++;
                if(flag) break;
            }
        }
    }
    return ans;
}
