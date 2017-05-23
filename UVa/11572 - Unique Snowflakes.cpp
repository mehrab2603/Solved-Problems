#include <bits/stdc++.h>

using namespace std;
map <int, int> flakes;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        flakes.clear();
        int n, ans = 0, top = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if(flakes.find(x) != flakes.end() && flakes[x] >= top) {
                ans = max(ans, i - top);
                top = flakes[x] + 1;
            }
            flakes[x] = i;
        }
        ans = max(ans, n - top);

        printf("%d\n", ans);
    }
    return 0;
}
