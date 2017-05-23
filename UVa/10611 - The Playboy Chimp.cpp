#include<bits/stdc++.h>
#define MAX 50010

using namespace std;

int arr[MAX];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int q;
    scanf("%d", &q);
    while(q--) {
        int height;
        scanf("%d", &height);
        int ansLow, ansHigh;
        int lo = 0, hi = n - 1, mid;
        while(lo < hi) {
            mid = lo + (hi - lo + 1) / 2;
            if(arr[mid] >= height) hi = mid - 1;
            else lo = mid;
        }
        ansLow = lo;
        lo = 0, hi = n - 1;
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            if(arr[mid] <= height) lo = mid + 1;
            else hi = mid;
        }
        ansHigh = lo;
        if(arr[ansHigh] <= height) printf("%d X\n", arr[ansLow]);
        else if(arr[ansLow] >= height) printf("X %d\n", arr[ansHigh]);
        else if(arr[ansHigh] == height && arr[ansLow] == height) printf("X X\n");
        else printf("%d %d\n", arr[ansLow], arr[ansHigh]);
    }
    return 0;
}
