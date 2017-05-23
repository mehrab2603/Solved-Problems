#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        multiset<int> bills;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int k;
            scanf("%d", &k);
            for(int i = 0; i < k; i++) {
                int x;
                scanf("%d", &x);
                bills.insert(x);
            }
            ans += *bills.rbegin() - *bills.begin();
            set<int>::iterator it = bills.end();
            it--;
            bills.erase(it);
            bills.erase(bills.begin());
        }
        printf("%lld\n", ans);
    }
    return 0;
}
