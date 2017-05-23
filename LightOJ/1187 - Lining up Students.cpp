#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if(i > 0 && i - x <= ans)
                ans++;
        }
        printf("Case %d: %d\n", ++caseno, ans + 1);
    }
    return 0;
}
