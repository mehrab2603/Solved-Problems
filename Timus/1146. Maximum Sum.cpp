#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;
int mat[MAX][MAX], cum[MAX][MAX];


int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
    for(int i = 0; i < n; i++) cum[0][i] = mat[0][i];
    for(int i = 1; i < n; i++)
        for(int j = 0; j < n; j++)
            cum[i][j] = cum[i - 1][j] + mat[i][j];
    int ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int maximum = 0, negativeMaximum = INT_MIN, positiveMaximum = INT_MIN;
            bool positiveFlag = false;
            for(int k = 0; k < n; k++) {
                int val;
                if(i == 0) val = cum[j][k];
                else val = cum[j][k] - cum[i - 1][k];

                if(val >= 0) positiveFlag = true;
                if(!positiveFlag) negativeMaximum = max(negativeMaximum, val);
                maximum += val;
                if(maximum < 0) maximum = 0;
                positiveMaximum = max(maximum, positiveMaximum);
            }
            if(!positiveFlag) ans = max(ans, negativeMaximum);
            else ans = max(ans, positiveMaximum);
        }
    }
    printf("%d\n", ans);

    return 0;
}
