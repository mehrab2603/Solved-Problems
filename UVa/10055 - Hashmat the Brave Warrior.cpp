#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long x1, x2;
    while(scanf("%lld %lld", &x1, &x2) == 2)
        printf("%lld\n", (x2 - x1 < 0? x1 - x2 : x2 - x1));

    return 0;
}
