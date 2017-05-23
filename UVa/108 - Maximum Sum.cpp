#include <bits/stdc++.h>

using namespace std;

int arr[110][110], cum[110][110], final[210][210];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);


    for(int i = n - 1; i >= 0; i--)
        for(int j = 0; j < n; j++)
            cum[i][j] = arr[i][j] + cum[i + 1][j];


    int ans = INT_MIN;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int val, sum = 0;
            for(int k = 0; k < n; k++) {
                val = cum[i][k] - cum[j + 1][k];
                sum += val;
                if(sum < 0) sum = 0;
                ans = max(ans, sum);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
