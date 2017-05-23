#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m;
    while(cin >> n >> m)
    {
        long long mult = 1;
        /*
        for(long long i = n; i >= n - m + 1; i--)
        {
            mult = (mult * i) ;
            while(mult % 10 == 0)
                mult /= 10;
            mult %= 100000000;
        }
        */
        for(long long i = n - m + 1; i <= n; i++)
        {
            mult = (mult * i) ;
            while(mult % 10 == 0)
                mult /= 10;
            mult %= 100000000;
        }
        //cout << "mult = " << mult << endl;
        long long ans;
        while(mult)
        {
            long long digit = mult % 10;
            if(digit == 0)
                mult /= 10;
            else
            {
                ans = digit;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
