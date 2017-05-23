#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long t;
    scanf("%lld", &t);
    while(t--)
    {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        if(x > y) printf(">\n");
        else if(x < y) printf("<\n");
        else printf("=\n");
    }
    return 0;
}
