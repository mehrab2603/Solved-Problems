#include<bits/stdc++.h>

using namespace std;

long long mulmod(long long a,long long b,long long c) {
    long long x = 0,y = a % c;
    while(b) {
        if(b & 1){
            x = (x + y) % c;
        }
        y = (y * 2) % c;
        b >>= 1;
    }
    return x % c;
}

long long modulo(long long a,long long b,long long c) {
    long long x = 1, y = a;
    while(b) {
        if(b & 1) {
            x = mulmod(x, y, c); //replace with mulmod(x, y, c) to avoid overflow
        }
        y = mulmod(y, y, c); // squaring the base. replace with mulmod(y, y, c) to avoid overflow
        b >>= 1;
    }
    return x % c;
}

bool miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

long long gcd(long long a,long long b) { return !b ? a : gcd(b, a % b); } // standard gcd

long long pollard(long long n) {
    int i = 0, k = 2;
    long long x = 3, y = 3; // random seed = 3, other values possible
    while (1) {
        i++;
        x = (mulmod(x, x, n) + n - 1) % n; // generating function
        long long d = gcd((y - x) > 0 ? (y - x) : (x - y), n); // the key insight
        if (d != 1 && d != n) return d; // found one non-trivial factor
        if (i == k) y = x, k *= 2;
    }
}

set< long long > factor;
map< long long, long long > power;

void factorize(long long n) {
    if(n % 2 == 0) {
        factor.insert(2);
        int counter = 0;
        while(n % 2 == 0) {
            n /= 2;
            counter++;
        }
        power[2] += counter;
    }
    long long sq = sqrt(n);
    for(long long i = 3; i <= sq; i += 2) {
        if(n % i == 0) {
            factor.insert(i);
            int counter = 0;
            while(n % i == 0) {
                n /= i;
                counter++;
            }
            power[i] += counter;
            sq = sqrt(n);
        }
    }
    if(n > 1) {
        factor.insert(n);
        power[n]++;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        factor.clear();
        power.clear();
        long long n;
        scanf("%lld", &n);
        if(miller(n, 20)) printf("%lld = %lld\n", n, n);
        else {
            printf("%lld =", n);
            long long first = pollard(n);
            long long second = n / first;
            factorize(first);
            factorize(second);
            set< long long >::iterator beforeLast = factor.end();
            beforeLast--;
            for(set< long long >::iterator it = factor.begin(); it != factor.end(); it++) {
                long long x = *it;
                if(power[x] > 1) printf(" %lld^%lld", x, power[x]);
                else printf(" %lld", x);
                if(it != beforeLast) printf(" *");
            }
            printf("\n");
        }
    }
    return 0;
}
