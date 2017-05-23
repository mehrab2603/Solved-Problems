#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005, MOD = 1000000007;
int k[1005];

long long fact[1000006];

//Extended Euclid
typedef pair<long long, long long> pii;
#define x first
#define y second

pii extendedEuclid(long long a, long long b) { // returns x, y | ax + by = gcd(a,b)
    if(b == 0) return pii(1, 0);
    else {
        pii d = extendedEuclid(b, a % b);
        return pii(d.y, d.x - d.y * (a / b));
    }
}

//Modular Inverse
int modularInverse(long long a, long long n) {
    pii ret = extendedEuclid(a, n);
    return ((ret.x % n) + n) % n;
}

void precalc() {
    fact[0] = 1;
    for(int i = 1; i <= 1000005; i++) fact[i] = (fact[i - 1] * i) % MOD;
}


int main() {
    precalc();
    int t, caseno = 0;
    scanf("%d", &t);
    getchar();
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &k[i]);
        int ans = 1, sum = k[0];
        for(int i = 1; i < n; i++) {
            int now = k[i], previous = k[i - 1];
            sum += now;
            ans = (ans * ((fact[sum - 1] * modularInverse(fact[now - 1] * fact[sum - now], MOD)) % MOD)) % MOD;

        }
        printf("Case %d: %d\n", ++caseno, ans);
    }
    return 0;
}
