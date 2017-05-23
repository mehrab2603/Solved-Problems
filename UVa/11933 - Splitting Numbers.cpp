#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) && n)
    {
        int a = 0, b = 0;
        int i = 0;
        bool flag = false;
        while(n)
        {
            if(n & 1)
            {
                if(!flag) a = a | (1 << i);
                else b = b | (1 << i);
                flag = !flag;
            }
            n = n >> 1;
            i++;
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}
