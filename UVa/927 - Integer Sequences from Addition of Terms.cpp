#include<bits/stdc++.h>

using namespace std;

int coefficient[25];

int main() {
    int c;
    scanf("%d%*c", &c);
    while(c--) {
        int power;
        scanf("%d", &power);
        for(int i = 0; i <= power; i++) scanf("%d", &coefficient[i]);
        int d;
        scanf("%d", &d);
        int k;
        scanf("%d", &k);

        int sum = 0, n = 0;
        while(sum < k) sum += ++n * d;
        long long ans = 0, temp = 1;
        for(int i = 0; i <= power; i++) {
            ans += coefficient[i] * temp;
            temp *= n;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
