#include<bits/stdc++.h>

using namespace std;

int bigmod(int, int, int);

int main() {
    int b, p, m;
    while(scanf("%d %d %d", &b, &p, &m) != EOF) {
        printf("%d\n", bigmod(b, p, m));
    }
    return 0;
}

int bigmod(int a, int b, int m) {
    if(b == 0) return 1;
    int x = bigmod(a, b / 2, m) % m;
    x = ((x % m) * (x % m)) % m;
    if(b % 2 == 1) x = ((x % m) * (a % m)) % m;
    return x;
}
