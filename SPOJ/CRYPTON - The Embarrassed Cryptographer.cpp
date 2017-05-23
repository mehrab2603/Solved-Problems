#include<bits/stdc++.h>

using namespace std;

char k[102];

int longdiv(int n) {
    int length = strlen(k);
    int mod = 0;
    for(int i = 0; i < length; i++) {
        mod = mod * 10 + (k[i] - '0');
        mod = mod % n;
    }
    return mod == 0;
}

#define M 1000005
unsigned marked[(M >> 6) + 2] = {0};

#define on(x) (marked[x >> 6] & (1 << ((x >> 1) & 31)))
#define mark(x)  (marked[x >> 6] |= (1 << ((x >> 1) & 31)))


void sieve(int n) {
    for (int i = 3; i * i <= n; i += 2) {
        if (!on(i)) {
            for(int j= i * i, k = i << 1; j <= n; j+=k) {
                mark(j);
            }
        }
    }
}

bool isPrime(int num) {
    return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}

vector< int > primes;

void genPrime(int n) {
    primes.push_back(2);
    for(int i = 3; i <= n; i += 2) if(isPrime(i)) primes.push_back(i);
}


int main() {
    sieve(1000000);
    genPrime(1000000);
    int l;
    while(scanf("%s %d", k, &l) && strcmp(k, "0") != 0 && l != 0) {
        getchar();
        bool bad = false;
        for(int i = 0; i < primes.size() && primes[i] < l; i++) {
            if(longdiv(primes[i])) {
                printf("BAD %d\n", primes[i]);
                bad = true;
                break;
            }
        }
        if(!bad) printf("GOOD\n");
    }
    return 0;
}
