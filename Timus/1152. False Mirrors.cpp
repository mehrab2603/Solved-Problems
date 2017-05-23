#include <bits/stdc++.h>

using namespace std;

int dp[1048580], arr[25];

int setBit(int number, int index) {
    return number | (1 << index);
}

int resetBit(int number, int index) {
    return number & ~(1 << index);
}

bool isSet(int number, int index) {
    return number & (1 << index);
}

int func(int mask, int n, int fin) {
    if(mask == fin) return 0;
    int &ret = dp[mask];
    if(ret != -1) return ret;
    ret = 9999999;
    int total = 0;
    for(int i = 0; i < n; i++)
        if(!isSet(mask, i))
            total += arr[i];
    for(int i = 0; i < n; i++) {
        int temp = total;
        if(!isSet(mask, i % n)) {temp -= arr[i % n];}
        else continue;
        if(!isSet(mask, (i + 1) % n)) {temp -= arr[(i + 1) % n];}
        if(!isSet(mask, (i + 2) % n)) {temp -= arr[(i + 2) % n];}
        ret = min(ret, temp + func(setBit(setBit(setBit(mask, i), (i + 1) % n), (i + 2) % n), n, fin));
    }
    return ret;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    memset(dp, -1, sizeof dp);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d\n", func(0, n, (1 << n) - 1));
    return 0;
}
