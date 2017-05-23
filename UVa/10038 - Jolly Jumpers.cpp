#include <bits/stdc++.h>

using namespace std;
bool taken[3010];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(taken, false, sizeof taken);
        if(n == 1) {while (getchar() != '\n'); printf("Jolly\n"); continue;}
        int temp;
        scanf("%d", &temp);
        for(int i = 1; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            int diff = x - temp;
            if(diff < 0) diff *= -1;
            taken[diff] = true;
            temp = x;
        }
        bool flag = false;
        for(int i = 1; i < n; i++)
            if(!taken[i])
                {flag = true; break;}
        if(flag) printf("Not jolly\n");
        else printf("Jolly\n");
    }
    return 0;
}
