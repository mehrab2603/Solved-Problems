#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int maxi = 0;
        int sq = (int)sqrt(n);
        for(int i = 2; i <= sq; i++) {
            if(n % i == 0) {
                int counter = 0;
                while(n % i == 0) {
                    counter++;
                    n /= i;
                }
                maxi = max(counter, maxi);
                sq = sqrt(n);
            }
        }
        if(n > 1 && maxi == 0) maxi = 1;
        printf("%d\n", maxi);
    }
    return 0;
}
