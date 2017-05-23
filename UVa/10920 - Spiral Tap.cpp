#include <bits/stdc++.h>
#define MAX 100010

using namespace std;
int sz, x, y;
long long p;
long long goLeft(long long);
long long goRight(long long);
long long goUp(long long);
long long goDown(long long);

int main()
{
    //freopen("input.txt", "r", stdin);
    while(scanf("%d %lld", &sz, &p) && (sz || p))
    {
        if(p == 1) {printf("Line = %d, column = %d.\n", (sz / 2) + 1, (sz / 2) + 1); continue;}
        int level = (int)ceil(sqrt(p));
        if(level % 2 == 0) level++;
        long long curr = ((level - 2) * (level - 2)) + 1, counter = level - 2;
        x = (sz / 2) + ((level + 1) / 2);
        y = x - 1;
        while(curr != p)
        {
            for(int i = 0; i < counter && curr != p; i++)
                    curr = goLeft(curr);
            counter++;
            for(int i = 0; i < counter && curr != p; i++)
                    curr = goDown(curr);
            for(int i = 0; i < counter && curr != p; i++)
                    curr = goRight(curr);
            for(int i = 0; i < counter && curr != p; i++)
                    curr = goUp(curr);
        }
        printf("Line = %d, column = %d.\n", x, y);
    }
    return 0;
}

long long goLeft(long long curr)
{
    curr++;
    y--;
    return curr;
}

long long goRight(long long curr)
{
    curr++;
    y++;
    return curr;
}

long long goUp(long long curr)
{
    curr++;
    x++;
    return curr;
}

long long goDown(long long curr)
{
    curr++;
    x--;
    return curr;
}
