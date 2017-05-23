#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr;
        int p = n;
        while(p--)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        printf("Case %d: %d\n", ++caseno, arr[((n + 1) / 2) - 1]);
    }
    return 0;
}
