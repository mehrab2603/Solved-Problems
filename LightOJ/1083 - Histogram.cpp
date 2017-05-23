#include<bits/stdc++.h>
#define MAX 30010

using namespace std;

int arr[MAX], tree[4 * MAX], n;

void build(int, int, int);
int query(int, int, int, int, int);
int func(int, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        build(1, 0, n - 1);
        printf("Case %d: %d\n", ++caseno, func(0, n - 1));
    }
    return 0;
}

void build(int node, int b, int e) {
    if(b == e) {
        tree[node] = b;
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    if(arr[tree[left]] < arr[tree[right]])
        tree[node] = tree[left];
    else
        tree[node] = tree[right];
}

int query(int node, int b, int e, int i, int j) {
    if(b > j || e < i) return -1;
    if(b >= i && e <= j) return tree[node];
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    int lq = query(left, b, mid, i, j), rq = query(right, mid + 1, e, i, j);
    if(lq == -1) return rq;
    else if(rq == -1) return lq;
    else if(arr[lq] < arr[rq]) return lq;
    else return rq;
}

int func(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= n || i > j) return -INT_MAX;
    if(i == j) return arr[tree[i]];
    int lo = query(1, 0, n - 1, i, j);
    return max(arr[lo] * (j - i + 1), max(func(i, lo - 1), func(lo + 1, j)));
}
