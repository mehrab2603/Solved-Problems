#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) && (n || m)) {
        long long ans = 1;
        if(n - m > m)
            for(int i = 0; i < m; i++)
                ans = ((ans * (n - i))/ (i + 1));
        else
            for(int i = 0; i < n - m; i++)
                ans = ((ans * (n - i))/ (i + 1));
        printf("%d things taken %d at a time is %lld exactly.\n", n, m, ans);
    }
    return 0;
}
