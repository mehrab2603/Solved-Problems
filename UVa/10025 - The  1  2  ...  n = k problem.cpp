#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    bool flag = false;
    while(t--)
    {
        if(!flag) flag = true;
        else printf("\n");
        long long n;
        scanf("%I64d", &n);
        if(n < 0) n *= -1;
        else if(n == 0)
        {
            printf("3\n");
            continue;
        }
        long long ans = (-1 + sqrt(1 + (8 * n))) / 2;
        long long temp = (ans * (ans + 1)) / 2;
        if(temp == n) printf("%I64d\n", ans);
        else
        {
            while(1)
            {
                ans++;
                temp += ans;
                if((temp - n) % 2 == 0) break;
            }
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
