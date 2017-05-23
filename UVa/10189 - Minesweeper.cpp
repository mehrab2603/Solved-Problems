#include <bits/stdc++.h>

using namespace std;
string mat[110];
int mat2[110][110];
int n, m;
int dirx[] = {0, 0, -1, -1, -1, 1, 1, 1};
int diry[] = {-1, 1, -1, 0, 1, -1, 0, 1};

int main()
{
    int caseno = 0;
    bool flag = false;
    while(scanf("%d %d", &n, &m) && (n || m))
    {
        if(flag) printf("\n");
        else flag = true;
        for(int i = 0; i < n; i++)
            cin >> mat[i];
        for(int i = 0; i < n; i++)
            for(int  j = 0; j < m; j++)
                mat2[i][j] = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == '*')
                {
                    for(int k = 0; k < 8; k++)
                    {
                        int tempx = i + dirx[k];
                        int tempy = j + diry[k];
                        if(tempx >= 0 && tempx < n && tempy >= 0 && tempy < m)
                            mat2[tempx][tempy]++;
                    }
                }
            }
        }
        printf("Field #%d:\n", ++caseno);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == '*')
                    printf("*");
                else printf("%d", mat2[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}
