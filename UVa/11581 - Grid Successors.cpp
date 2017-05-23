#include <bits/stdc++.h>

using namespace std;
int mat[3][3];
bool isInfinite();
bool f();

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    getchar();
    while(n--)
    {
        getchar();
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                char ch = getchar();
                mat[i][j] = ch - '0';
            }
            getchar();
        }
        if(isInfinite()) {printf("-1\n"); continue;}
        int ans;
        for(int i = 1;; i++)
            if(!f() || isInfinite()) {ans = i - 1; break;}
        printf("%d\n", ans);
    }
    return 0;
}

bool isInfinite()
{
    bool flag = true;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(mat[i][j] == 1) {flag = false; break;}
    return flag;
}

bool f()
{
    bool flag = false;
    int mat2[3][3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            mat2[i][j] = mat[i][j];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int sum = 0;
            if(i - 1 >= 0) sum += mat2[i - 1][j];
            if(i + 1 < 3) sum += mat2[i + 1][j];
            if(j - 1 >= 0) sum += mat2[i][j - 1];
            if(j + 1 < 3) sum += mat2[i][j + 1];
            sum = sum % 2;
            if(sum != mat[i][j]) flag = true;
            mat[i][j] = sum;
        }
    }
    return flag;
}
