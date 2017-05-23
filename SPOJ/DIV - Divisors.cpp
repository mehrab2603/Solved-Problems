#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000005;
int d[MAX];
bool isPrime[250];

int sieve(int n) {
    d[1] = 1;
    isPrime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(i <= 240) {
            if(!d[i]) isPrime[i] = true;
            else isPrime[i] = false;
        }
        d[i]++;
        for(int j = i; j <= n; j += i) d[j]++;
    }
}

int primes[] = {2, 3, 5, 7, 11, 13};

int main() {
    sieve(1000000);

    int counter = 0;
    for(int i = 1; i <= 1000000; i++) {
        for(int j = 0; j < 6; j++) {
            if(d[i] % primes[j] == 0 && d[i] != primes[j] * primes[j] && isPrime[d[i] / primes[j]]) {
                counter++;
                break;
            }
        }
        if(counter == 9) {
            printf("%d\n", i);
            counter = 0;
        }
    }
    return 0;
}
