#include <stdio.h>
#include <stdlib.h>

long int n, a, b, c, d, e, f;
long int fn( int n ) {
    switch (n)
    {
        case 0: return a;
        case 1: return b;
        case 2: return c;
        case 3: return d;
        case 4: return e;
        case 5: return f;
        default:
                return( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) );
    }


}
int main() {
    int  caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%ld %ld %ld %ld %ld %ld %ld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %ld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
