#include<bits/stdc++.h>
#define MAX 100010

using namespace std;

int arr[MAX];

int binarySearch1(int, int, int);
int binarySearch2(int, int, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("Case %d:\n", ++caseno);
        while(q--) {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", binarySearch2(0, n - 1, b) - binarySearch1(0, n - 1, a));
        }
    }
    return 0;
}

int binarySearch1(int lo, int hi, int target) {
    int mid;
    while(lo < hi) {
        mid = (hi + lo + 1) / 2;
        if(arr[mid] >= target) hi = mid - 1;
        else lo = mid;
    }
    if(arr[lo] >= target) return 0;
    return lo + 1;
}

int binarySearch2(int lo, int hi, int target) {
    int mid;
    while(lo < hi) {
        mid = (lo + hi + 1) / 2;
        if(arr[mid] > target) hi = mid - 1;
        else lo = mid;
    }
    if(arr[lo] > target) return 0;
    else return lo + 1;
}
