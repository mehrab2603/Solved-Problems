#include <bits/stdc++.h>

using namespace std;
bool taken[300];
double val[300];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int k;
        scanf("%d", &k);
        getchar();
        memset(taken, false, sizeof taken);
        for(int i = 0; i < k; i++)
        {
            char ch;
            double cost;
            scanf("%c %lf", &ch, &cost);
            getchar();
            taken[(int)ch] = true;
            val[(int)ch] = cost;
        }
        int m;
        scanf("%d", &m);
        getchar();
        double ans = 0;
        for(int i = 0; i < m; i++)
        {
            char ch;
            while((ch = getchar()) != '\n')
                if(taken[(int)ch]) ans += val[(int)ch];
        }
        printf("%.2lf$\n", ans / 100);
    }
}
