#include <bits/stdc++.h>
#define MAX 110

using namespace std;
int x[MAX], y[MAX];
int c[MAX][MAX];
char b[MAX][MAX];
void lcs();
void print(int, int);
int n1, n2;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int caseno = 0;
    while(scanf("%d %d", &n1, &n2) && (n1 || n2))
    {
        for(int i = 0; i < n1; i++) scanf("%d", &x[i]);
        for(int i = 0; i < n2; i++) scanf("%d", &y[i]);
        lcs();
        cout << "Twin Towers #" << ++caseno << endl;
        cout << "Number of Tiles : "  << c[n1][n2] << endl;;
        //cout << "Order :";
        //print(n1, n2);
        //cout << endl;
        cout << endl;
    }
    return 0;
}

void lcs()
{
    for(int i = 0; i < n1 + 1; i++)
        c[0][i] = 0;
    for(int i = 0; i < n2 + 1; i++)
        c[i][0] = 0;
    for(int i = 1; i < n1 + 1; i++)
    {
        for(int j = 1; j < n2 + 1; j++)
        {
            if(x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'c';
            }
            else
            {
                if(c[i - 1][j] >= c[i][j - 1])
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 'x';
                }
                else
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 'y';
                }
            }
        }
    }
}

void print(int i, int j)
{
    if(i == 0 || j == 0) return;
    if(b[i][j] == 'c')
    {
        print(i - 1, j - 1);
        cout << " " << x[i - 1];
    }
    else if(b[i][j] == 'x')
        print(i - 1, j);
    else
        print(i, j - 1);
}
