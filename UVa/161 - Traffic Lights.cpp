#include <bits/stdc++.h>

using namespace std;

vector <int> t1;

int main()
{
    int x;
    while(cin >> x)
    {
        if(x) t1.push_back(x);
        else if(t1.size() > 0)
        {
            bool flag = false;
            int ans;
            sort(t1.begin(), t1.end());
            for(int i = t1[0]; i <= 18000; i++)
            {
                for(int j = 0; j < (int)t1.size(); j++)
                {
                    if(i % (2 * t1[j]) >= t1[j] - 5) break;
                    if(j == (int)t1.size() - 1) {flag = true; ans = i; break;}
                }
                if(flag) break;

            }
            if(!flag) {printf("Signals fail to synchronise in 5 hours\n"); t1.clear(); continue;}
            int hh = 0, mm = 0, ss = 0;
            if(ans >= 3600) {hh = ans / 3600; ans = ans % 3600;}
            if(ans >= 60) {mm = ans / 60; ans = ans % 60;}
            ss = ans;
            printf("0%d:", hh);
            if(mm < 10) printf("0%d:", mm);
            else printf("%d:", mm);
            if(ss < 10) printf("0%d\n", ss);
            else printf("%d\n", ss);
            t1.clear();
        }
    }
    return 0;
}
