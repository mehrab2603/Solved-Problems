#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long x, y;
        cin >> x >> y;
        double a = (x + y) / 2.0;
        double b = (x - y) / 2.0;
        if((int)a < a || (int)b < b) cout << "impossible"<< endl;
        else if(b < 0) cout << "impossible"<< endl;
        else cout << a << " " << b << endl;
    }
    return 0;
}
