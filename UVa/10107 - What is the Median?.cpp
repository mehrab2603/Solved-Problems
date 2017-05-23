#include <bits/stdc++.h>
#define MAX 10000

using namespace std;
int arr[MAX];
int ans[MAX];

int main()
{
    int n = 1;
    while(scanf("%d", &arr[n]) != EOF)
    {
        sort(arr, arr + n + 1);
        if(n % 2 == 0)
            ans[n] = .5 * ((long long)arr[n / 2] + (long long)arr[(n / 2) + 1]) + .000000001;
        else
            ans[n] = arr[(1 + n) / 2];
        n++;
    }
    for(int i = 1; i < n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
