#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int r, c;
        scanf("%d %d", &r, &c);
        printf("%d\n", (int)(ceil((r -2) / 3.0) * ceil((c - 2) / 3.0)));
    }
    return 0;
}
