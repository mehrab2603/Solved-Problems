#include<bits/stdc++.h>
#define MAX 100010

using namespace std;

int arr[MAX], n;
bool func(int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        arr[0] = 0;
        for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
        int lo = 0, hi = INT_MAX, mid;
        while(lo < hi) {
            mid = (lo + hi) / 2;
            if(func(mid)) hi = mid;
            else lo = mid + 1;
        }
        printf("Case %d: %d\n", ++caseno, lo);
    }
    return 0;
}

bool func(int energy) {
    if(n == 1) return energy >= arr[1];
    for(int i = 0; i < n; i++) {
        if(arr[i + 1] - arr[i] == energy) energy--;
        else if(arr[i + 1] - arr[i] > energy) return false;
    }
    return true;
}

