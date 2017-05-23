#include <bits/stdc++.h>
#define MAX 20

using namespace std;
int arr[MAX][MAX], vis[MAX][MAX];
bool rvis[MAX][MAX][4];
int tilecheck();
void offset();
int xoff, yoff, cx, cy, face;

int main()
{
    int r, c;
    while(scanf("%d %d", &r, &c) && r && c)
    {
        getchar();
        for(int i = 0; i < MAX; i++)
            for(int j = 0; j < MAX; j++)
                arr[i][j] = 1, vis[i][j] = 0;
        memset(rvis, false, sizeof rvis);
        for(int i = 1; i < r + 1; i++)
        {
            string s;
            getline(cin, s);
            for(int j = 0; j < (int)s.length(); j++)
            {
                int x = s[j] - '0';
                arr[i][j + 1] = x;
            }
        }
        face = 0;
        offset();
        cx = r, cy  = 1;
        while(1)
        {
            if(tilecheck())
            {
                vis[cx][cy]++;
                cx += xoff;
                cy += yoff;
                if(cx == r && cy == 1) break;
            }
            else
            {
                face = (face + 1) % 4;
                offset();
            }
        }
        int zero = 0, one = 0, two = 0, three = 0, four = 0;
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                if(arr[i][j] == 0)
                {
                    if(vis[i][j] == 0) zero++;
                    else if(vis[i][j] == 1) one++;
                    else if(vis[i][j] == 2) two++;
                    else if(vis[i][j] == 3) three++;
                    else if(vis[i][j] == 4) four++;
                }
            }
        }
        printf("%3d%3d%3d%3d%3d\n", zero, one, two, three, four);

    }
    return 0;
}

int tilecheck()
{
    int i = cx, j = cy;
    if(face == 0)
    {
        if(arr[i + 1][j] == 1)
        {
            bool right = rvis[i + 1][j][face];
            rvis[i + 1][j][face] = true;
            if(right == false && arr[i][j + 1] == 0)
                return 1;
            else return 0;
        }
        else
        {
            face = (face + 4 - 1) % 4;
            offset();
            return 1;
        }
    }
    else if(face == 1)
    {
        if(arr[i][j + 1] == 1)
        {
            bool right = rvis[i][j + 1][face];
            rvis[i][j + 1][face] = true;
            if(right == false && arr[i - 1][j] == 0)
                return 1;
            else return 0;
        }
        else
        {
            face = (face + 4 - 1) % 4;
            offset();
            return 1;
        }
    }
    else if(face == 2)
    {
        if(arr[i - 1][j] == 1)
        {
            bool right = rvis[i - 1][j][face];
            rvis[i - 1][j][face] = true;
            if(right == false && arr[i][j - 1] == 0)
                return 1;
            else return 0;
        }
        else
        {
            face = (face + 4 - 1) % 4;
            offset();
            return 1;
        }
    }
    else
    {
        if(arr[i][j - 1] == 1)
        {
            bool right = rvis[i][j - 1][face];
            rvis[i][j - 1][face] = 2;
            if(right == false && arr[i + 1][j] == 0)
                return 1;
            else return 0;
        }
        else
        {
            face = (face + 4 - 1) % 4;
            offset();
            return 1;
        }
    }
}

void offset()
{
    if(face == 0)
        xoff = 0, yoff = 1;
    else if(face == 1)
        xoff = -1, yoff = 0;
    else if(face == 2)
        xoff = 0, yoff = -1;
    else if(face == 3)
        xoff = 1, yoff = 0;
}
