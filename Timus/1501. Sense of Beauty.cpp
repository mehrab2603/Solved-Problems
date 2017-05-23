#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int pilemaker(int, int, int);
int n;
char pile1[1001];
char pile2[1001];
int dp[1001][1001][5];
bool vis[1001][1001][5] = {false};
int dir[1001][1001][5] = {0};

int main()
{

    scanf("%d", &n);
    scanf("%s %s", pile1, pile2);
    if(pilemaker(0, 0, 2) == 1)
    {
        int index1 = 0, index2 = 0, dif = 2;
        while(dir[index1][index2][dif])
        {
            if(dir[index1][index2][dif] == 1)
            {
                printf("1");
                index1 += 1;
                dif += 1;
            }
            else if(dir[index1][index2][dif] == 2)
            {
                printf("1");
                index1 += 1;
                dif -= 1;
            }
            else if(dir[index1][index2][dif] == 3)
            {
                printf("2");
                index2 += 1;
                dif += 1;
            }
            else
            {
                printf("2");
                index2 += 1;
                dif -= 1;
            }
        }
    }
    else
        puts("Impossible");

    return 0;
}

int pilemaker(int i, int j, int dif)
{
    if(i == n && j == n) return 1;
    if(dif > 3 || dif < 1) return 0;
    if(vis[i][j][dif] == true) return dp[i][j][dif];
    int ret1 = 0, ret2 = 0, ret3 = 0, ret4 = 0;
    if(i < n)
    {
        //printf("1=%c\n", pile1[i]);
        if(pile1[i] == '1') ret1 = pilemaker(i + 1, j, dif + 1);
        else ret2 = pilemaker(i + 1, j, dif - 1);
    }
    if(j < n)
    {
        //printf("2=%c\n", pile2[j]);
        if(pile2[j] == '1') ret3 = pilemaker(i, j + 1, dif + 1);
        else ret4 = pilemaker(i, j + 1, dif - 1);
    }
    if(ret1 == 1) dir[i][j][dif] = 1;
    else if(ret2 == 1) dir[i][j][dif] = 2;
    else if(ret3 == 1) dir[i][j][dif] = 3;
    else dir[i][j][dif] = 4;
    dp[i][j][dif] = ret1 | ret2 | ret3 | ret4;
    //printf("%d\n", dp[i][j][dif]);
    vis[i][j][dif] = true;
    return dp[i][j][dif];
}
