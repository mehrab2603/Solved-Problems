#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-10;
const int MOD = 100000007, MAX = 2 * 102230 + 5;

vector< long long > pp;
int fact[MAX], catalan[MAX];

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
long long modularInverse(long long a, long long n) {
	pii ret = extendedEuclid(a, n);
	return ((ret.x % n) + n) % n;
}


void precalc() {
    set< long long > temp;
    for(long long i = 2; i <= 100000; i++) {
        long long num = i * i;
        while(num <= 10000000000ll) {
            temp.insert(num);
            num *= i;
        }
    }
    for(set< long long >::iterator it = temp.begin(); it != temp.end(); it++) pp.push_back(*it);
    fact[0] = 1;
    for(int i = 1; i < MAX; i++) fact[i] = (((long long)fact[i - 1]) * i) % MOD;

    catalan[0] = 1;
    catalan[1] = 1;
    for(int i = 2; i < MAX / 2; i++) catalan[i] = ((fact[2 * i] % MOD) * modularInverse((((long long)fact[i + 1]) * fact[i]) % MOD, MOD)) % MOD;
}

int binarySearch(long long n) {
    int lo = 0, hi = pp.size() - 1;
    while(lo < hi) {
        int mid = (lo + hi) / 2 + 1;
        if(pp[mid] <= n) lo = mid;
        else if(pp[mid] > n) hi = mid - 1;
    }
    if(pp[lo] > n) return 0;
    return lo + 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    precalc();

    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        int n = binarySearch(b) - binarySearch(a - 1);

        printf("Case %d: %d\n", ++caseno, n ? (int)catalan[n] : 0);
    }
    return 0;
}
