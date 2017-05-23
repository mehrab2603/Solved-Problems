#include<bits/stdc++.h>

using namespace std;

int arr[35], ans;
vector< int > firstHalf, secondHalf;

void func(int, int, int, int, bool, bool);
int binarySearch(int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        firstHalf.clear();
        secondHalf.clear();
        int n, w;
        scanf("%d %d", &n, &w);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        int mid = n / 2;
        ans = 1;
        func(0, 0, w, mid, false, false);
        func(mid, 0, w, n, true, false);
        sort(firstHalf.begin(), firstHalf.end());
        for(int i = 0; i < secondHalf.size(); i++) {
            ans += binarySearch(w - secondHalf[i]);
        }
        printf("Case %d: %d\n", ++caseno, ans);
    }
}

void func(int index, int sum, int w, int bound, bool mode, bool taken) {
    if(index == bound) {
        if(!mode && taken) {
            firstHalf.push_back(sum);
            ans++;
        }
        else if(taken) {
            secondHalf.push_back(sum);
            ans++;
        }
        return;
    }
    func(index + 1, sum, w, bound, mode, taken);
    if(INT_MAX - sum >= arr[index] && sum + arr[index] <= w) func(index + 1, sum + arr[index], w, bound, mode, true);
}

int binarySearch(int target) {
    int lo = 0, hi = firstHalf.size() - 1, mid;
    while(lo < hi) {
        mid = (lo + hi) / 2;
        if(firstHalf[mid] > target) hi = mid;
        else lo = mid + 1;
    }
    if(!firstHalf.size()) return 0;
    else if(firstHalf[lo] <= target) return firstHalf.size();
    else return lo;
}
