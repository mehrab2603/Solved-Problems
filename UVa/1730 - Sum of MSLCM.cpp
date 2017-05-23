#include<bits/stdc++.h>

using namespace std;

const int MAX = 20000001;

long long divSum[MAX + 5];

int sieve() {
    for(int i = 2; i <= MAX; i++) {
        for(int j = i; j <= MAX; j += i) {
            divSum[j] += i;
        }
    }
    for(int i = 2; i <= MAX; i++) divSum[i] += divSum[i - 1] + 1;
}

int main() {
    sieve();
    int x;
    while(scanf("%d", &x) && x) {
        printf("%lld\n", divSum[x]);
    }
    return 0;
}
