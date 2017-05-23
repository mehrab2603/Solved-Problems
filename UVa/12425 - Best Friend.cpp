#include<bits/stdc++.h>

using namespace std;

const int MAX = 10000;

int divCount;
map< long long, long long > phi;
long long divisors[MAX], precalc[MAX];

long long calcPhi(long long n) {
  long long ret = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      ret -= ret / i;
    }
  }
  if (n > 1) ret -= ret / n;
  return ret;
}

void div(long long n) {
    divCount = 0;
    for(long long i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            if(phi[i] == 0) phi[i] = calcPhi(i);
            if(i != n / i && phi[n / i] == 0) phi[n / i] = calcPhi(n / i);
            divisors[divCount++] = i;
            if(i != n / i) divisors[divCount++] = n / i;
        }
    }
    sort(divisors, divisors + divCount);
    long long sum = 0;
    for(int i = 0; i < divCount; i++) {
        sum += phi[n / divisors[i]];
        precalc[i] = sum;
    }
}

int binSearch(long long x) {
    int lo = 0, hi = divCount - 1, mid;
    while(lo < hi) {
        mid = (lo + hi + 1) / 2;
        if(divisors[mid] > x) hi = mid - 1;
        else lo = mid;
    }
    return lo;
}


int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        long long n;
        int q;
        scanf("%lld %d", &n, &q);

        div(n);

        printf("Case %d\n", ++caseno);
        while(q--) {
            long long x;
            scanf("%lld", &x);
            long long index = binSearch(x);
            if(divisors[index] <= x)
                printf("%lld\n", precalc[index]);
            else
                printf("0\n");
        }
    }
    return 0;
}
