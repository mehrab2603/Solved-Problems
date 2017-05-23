#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000005;
int d[MAX];
bool mark[MAX];

void sieve(int n) {
    d[1] = 1;
    for(int i = 2; i <= n; i++) {
        d[i]++;
        for(int j = i; j <= n; j += i) d[j]++;
    }
}

vector< int > ans;

void sieve2(int k) {
    for(int m = 1; m <= k; m++) {
        for(int n = m; n <= k; n += m) {
            if(d[n] > 3) {
                if(d[n] % d[m] != 0) mark[n] = true;
            }
        }
    }
}

int main() {
    sieve(1000000);
    sieve2(1000000);
    int counter = 0;
    for(int i = 1; i <= 1000000; i++) {
        if(!mark[i] && d[i] > 3) counter++;
        if(counter == 108) {
            printf("%d\n", i);
            counter = 0;
        }
    }
    return 0;
}
