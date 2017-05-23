#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        int x1, y1, z1, x2, y2, z2, xin, yin, zin, n;
        x1 = -1; y1 = -1; z1 = -1;
        x2 = 9999; y2 = 9999; z2 = 9999;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d %d %d", &xin, &yin, &zin);
            x1 = max(x1, xin);
            y1 = max(y1, yin);
            z1 = max(z1, zin);
            scanf("%d %d %d", &xin, &yin, &zin);
            x2 = min(x2, xin);
            y2 = min(y2, yin);
            z2 = min(z2, zin);
        }
        if(x1 >= x2 || y1 >= y2 || z1 >= z2) printf("Case %d: 0\n", ++caseno);
        else printf("Case %d: %d\n", ++caseno, (x2 - x1) * (y2 - y1) * (z2 - z1));
    }
    return 0;
}
