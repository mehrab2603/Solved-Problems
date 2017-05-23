#include <bits/stdc++.h>

using namespace std;

long long func(long long);

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        long long m, n;
        scanf("%lld %lld", &m, &n);
        long long ans;
        if(m > 0)
            ans = func(n) - func(m - 1);
        else
            ans = func(n) + 1;
        printf("Case %d: %lld\n", ++caseno, ans);
    }
    return 0;
}

long long func(long long n) {
    long long power = 10, ans = 0;
    int digits = floor(log10(n)) + 1;
    for(int i = 0; i < digits; i++) {
        long long blocks = (n / power);
        ans += blocks * (power / 10);
        if(blocks) ans -= (power / 10) - 1;
        long long residue = n - (blocks * power);
        if(blocks && residue >= (power / 10)) {
            residue = (power / 10) - 1;
        }
        if(blocks && residue > 0) ans += residue;
        power *= 10;
    }
    return ans;
}
