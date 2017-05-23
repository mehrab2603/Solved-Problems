#include <bits/stdc++.h>
#define MAX 160

using namespace std;

int arr[MAX][MAX / 2], cum[MAX][MAX / 2];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &arr[i][j]);
        for(int i = n; i < 2 * n; i++)
            for(int j = 0; j < n; j++)
                arr[i][j] = arr[i - n][j];

        for(int i = 0; i < 2 * n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0) cum[i][j] = arr[i][j];
                else cum[i][j] = arr[i][j] + cum[i - 1][j];
            }
        }

        int ans = INT_MIN;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < 2 * n && (j - i + 1) <= n; j++) {
                int val, sumNormal = 0, sumRing = 0, total = 0, ansNormal = INT_MIN, ansRing = INT_MIN;
                for(int k = 0; k < n; k++) {

                    if(i == 0) val = cum[j][k];
                    else val = cum[j][k] - cum[i - 1][k];
                    total += val;

                    sumNormal += val;
                    ansNormal = max(ansNormal, sumNormal);
                    if(sumNormal < 0) sumNormal = 0;

                    sumRing += -val;
                    ansRing = max(ansRing, sumRing);
                    if(sumRing < 0) sumRing = 0;
                }
                ans = max(ans, max(ansNormal, total + ansRing));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

