#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
long long n, e, c;
typedef pair<long long, long long> pii;
pii extendedEuclid(long long, long long);
long long modularInverse(long long, long long);
long long bigmod(long long, long long, long long);

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(scanf("%lld %lld %lld", &n, &e, &c) != EOF)
    {
        long long p, q;
        for(int i = 3; i * i < n; i += 2)
        {
            if(n % i == 0)
            {
                p = i;
                q = n / p;
                break;
            }
        }
        long long totient = (p - 1) * (q - 1);
        long long d = modularInverse(e, totient);
        printf("%lld\n", bigmod(c, d, n));
    }
    return 0;
}

pii extendedEuclid(long long a, long long b)
{
    if(b == 0) return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.y, d.x - d.y * (a / b));
    }
}

long long modularInverse(long long a, long long n)
{
    pii ret = extendedEuclid(a, n);
    return ((ret.x % n) + n) % n;
}

long long bigmod(long long a, long long b, long long m)
{
    long long res = 1;
    while(b)
    {
        if(b & 1) res = (res * a) % m;
        b = b >> 1;
        a = (a * a) % m;
    }
    return res;
}
