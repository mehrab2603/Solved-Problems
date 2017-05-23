#include <bits/stdc++.h>

using namespace std;

int arr[15], powerOfFive[15];

void precalc() {
    powerOfFive[0] = 1;
    arr[0] = 0;
    int i = 1;
    while(i < 14) {
        arr[i] = powerOfFive[i - 1] + arr[i - 1];
        powerOfFive[i] = powerOfFive[i - 1] * 5;
        i++;
    }
}

int binarySearch(int x) {
    int lo = 0, hi = 13;
    while(lo < hi) {
        int mid = (lo + hi) / 2 + 1;
        if(arr[mid] <= x) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}


int main() {
    precalc();
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int q;
        scanf("%d", &q);
        int ans = 0;
        int lastIndex = -1, left = 4;
        while(q) {
            int index = binarySearch(q);
            if(index != lastIndex) {
                lastIndex = index;
                left = 4;
            }
            if(!left) break;
            q -= arr[index];
            ans += powerOfFive[index];
            left--;
        }
        if(q != 0) {
            printf("Case %d: impossible\n", ++caseno);
            continue;
        }

        printf("Case %d: %d\n", ++caseno, ans);
    }
    return 0;
}
