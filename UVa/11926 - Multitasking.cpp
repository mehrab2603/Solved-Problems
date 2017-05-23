#include <bits/stdc++.h>

using namespace std;
bool taken[1000010];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    while(scanf("%d %d", &n, &m) && (n || m))
    {
        memset(taken, false, sizeof taken);
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            for(int j = a; j < b && !flag; j++)
            {
                if(!taken[j]) taken[j] = true;
                else {flag = true;}
            }
        }
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            while(a < 1000000 && b <= 1000000 && !flag)
            {
                for(int j = a; j < b && !flag; j++)
                {
                    if(!taken[j]) taken[j] = true;
                    else {flag = true; break;}
                }
                a += c;
                b += c;
                if(b > 1000000) b = 1000000;
            }
        }
        if(flag) {printf("CONFLICT\n");}
        else {printf("NO CONFLICT\n");}
    }
    return 0;
}
