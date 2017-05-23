#include <bits/stdc++.h>

using namespace std;

long long divCount(long long);

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        long long n;
        scanf("%lld", &n);
        printf("Case %d: %lld\n", ++caseno, divCount(n) - 1);
    }
    return 0;
}

long long divCount(long long n) {
    long long ans = 1;
    int sq = sqrt(n);
    int counter = 0;
    while(n % 2 == 0) {
        n /= 2;
        counter++;
    }
    ans *= (counter + 1);
    sq = sqrt(n);
    for(int i = 3; i <= sq; i += 2) {
        counter = 0;
        if(n % i == 0) {
            while(n % i == 0) {
                n /= i;
                counter++;
            }
            ans *= (counter + 1);
            sq = sqrt(n);
        }
    }
    if(n > 1) ans *= 2;
    return ans;
}
