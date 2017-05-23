#include <bits/stdc++.h>

using namespace std;

int arr[2005];

int binarySerch(int n, int beg, int x) {
    int lo = beg, hi = n - 1;
    while(lo < hi) {
        int mid = (lo + hi) / 2 + 1;
        if(arr[mid] < x) lo = mid;
        else hi = mid - 1;
    }
    if(arr[lo] >= x) return 0;
    return lo - beg + 1;
}

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        sort(arr, arr + n);
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(j + 1 < n) ans += binarySerch(n, j + 1, arr[i] + arr[j]);
        printf("Case %d: %d\n", ++caseno, ans);
    }
    return 0;
}
