#include <bits/stdc++.h>

using namespace std;

const int MAX = 1429435;

int tree[4 * MAX], ans[100005];

void build(int n, int b, int e) {
    if(b == e) {
        tree[n] = b & 1;
        return;
    }
    int left = 2 * n, right = left + 1, mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[n] = tree[left] + tree[right];
    return;
}

void update(int n, int b, int e, int sum) {
    if(b == e) {
        tree[n] = 0;
        return;
    }
    int left = 2 * n, right = left + 1, mid = (b + e) / 2;
    if(sum > tree[left]) update(right, mid + 1, e, sum - tree[left]);
    else update(left, b, mid, sum);
    tree[n] = tree[left] + tree[right];
    return;
}

int query(int n, int b, int e, int sum) {
    if(b == e) return b;
    int left = 2 * n, right = left + 1, mid = (b + e) / 2;
    if(sum > tree[left]) return query(right, mid + 1, e, sum - tree[left]);
    else return query(left, b, mid, sum);
}

void precalc() {
    build(1, 0, MAX);
    ans[1] = 1;
    for(int i = 2; i <= 100000; i++) {
        ans[i] = query(1, 0, MAX, i);
        for(int j = (MAX / ans[i]) * ans[i]; j >= 0; j -= ans[i]) update(1, 0, MAX, j);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    precalc();
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("Case %d: %d\n", ++caseno, ans[n]);
    }
    return 0;
}
