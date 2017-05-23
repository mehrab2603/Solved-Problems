#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        vector <int> dist;
        for(int i = 0; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            dist.push_back(x);
        }
        int lo = *max_element(dist.begin(), dist.end());
        int hi = accumulate(dist.begin(), dist.end(), 0);
        int mid;
        while(lo < hi)
        {
            mid = lo + ((hi - lo) / 2);
            int tread = 0, req = 1;
            for(int i = 0; i < (int)dist.size(); i++)
            {
                if(tread + dist[i] <= mid)
                    tread += dist[i];
                else
                    req++, tread = dist[i];
            }
            if(req <= k + 1) hi = mid;
            else lo = mid + 1;
        }
        printf("Case %d: %d\n", ++caseno, lo);
        int tread = 0, counter = dist.size();
        for(int i = 0; i < (int)dist.size(); i++)
        {
            if(tread + dist[i] <= lo && counter >= k + 1)
                counter--, tread += dist[i];
            else
            {
                printf("%d\n", tread);
                k--;
                counter--;
                tread = dist[i];
            }
        }
        printf("%d\n", tread);
    }
    return 0;
}
