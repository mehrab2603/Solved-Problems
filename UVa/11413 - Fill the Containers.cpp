#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        vector<int> cap;
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            cap.push_back(x);
        }
        int lo = *max_element(cap.begin(), cap.end());
        int hi = accumulate(cap.begin(), cap.end(), 0);
        int mid;
        while(lo < hi)
        {
            mid = lo + ((hi - lo) / 2);
            int req = 1, load = 0;
            for(int i = 0; i < (int)cap.size(); i++)
            {
                if(load + cap[i] <= mid)
                    load = load + cap[i];
                else
                    req++, load = cap[i];
            }
            if(req <= m)
                hi = mid;
            else
                lo = mid + 1;
        }
        cout << lo << endl;

    }
    return 0;
}
