#include <bits/stdc++.h>

using namespace std;

const long long MAX = 1000000000000ll;

vector< long long > arr;
set< long long > mult;

void func(int index, long long num) {
    if(num > MAX) return;
    if(num <= MAX  && num != 1) mult.insert(num);
    if(index == (int)arr.size()) {
        if(num <= MAX && num != 1) mult.insert(num);
        return;
    }
    if(num <= MAX / arr[index]) func(index + 1, num);
    if(num <= MAX / arr[index]) func(index, num * arr[index]);
    if(num <= MAX / arr[index]) func(index + 1, arr[index] * num);
}

void precalc() {
    vector< long long > temp[15];
    temp[0].push_back(0);
    for(int i = 1; i <= 12; i++) {
        for(int j = 0; j < (int)temp[i - 1].size(); j++) {
            long long num1 = temp[i - 1][j] * 10 + 4, num2 = temp[i - 1][j] * 10 + 7;
            temp[i].push_back(num1);
            arr.push_back(num1);
            temp[i].push_back(num2);
            arr.push_back(num2);

        }
    }
    func(0, 1);
    arr.clear();
    for(set< long long >::iterator it = mult.begin(); it != mult.end(); it++) arr.push_back(*it);
}

int binarySearch(long long x) {
    int lo = 0, hi = arr.size() - 1;
    while(lo < hi) {
        int mid = (lo + hi) / 2 + 1;
        if(arr[mid] <= x) lo = mid;
        else hi = mid - 1;
    }
    if(arr[lo] > x) return 0;
    return lo + 1;
}

int main() {
    precalc();

    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        printf("Case %d: %d\n", ++caseno, binarySearch(b) - binarySearch(a - 1));
    }
    return 0;
}
