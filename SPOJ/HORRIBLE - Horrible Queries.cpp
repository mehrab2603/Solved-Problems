#include<bits/stdc++.h>
#define MAX 100010

using namespace std;

struct Node {
    long long sum, prop;
} tree[4 * MAX];

void build(int, int, int);
void propagate(int, int, int, long long);
void update(int, int, int, int, int, int);
long long query(int, int, int, int, int);

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, c;
        scanf("%d %d", &n, &c);
        build(1, 0, n - 1);
        for(int i = 0; i < c; i++) {
            int command;
            scanf("%d", &command);
            if(command == 0) {
                int p, q , v;
                scanf("%d %d %d", &p, &q, &v);
                update(1, 0, n - 1, p - 1, q - 1, v);
            }
            else {
                int p, q;
                scanf("%d %d", &p, &q);
                printf("%lld\n", query(1, 0, n - 1, p - 1, q - 1));
            }
        }
    }
    return 0;
}

void build(int node, int b, int e) {
    if(b == e) {
        tree[node].sum = 0;
        tree[node].prop = 0;
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node].sum = tree[left].sum + tree[right].sum;
    tree[node].prop = 0;
}

void update(int node, int b, int e, int i, int j, int newVal) {
    if(i > e || j < b) {
        tree[node].sum += (e - b + 1) * tree[node].prop;
        propagate(node, b, e, tree[node].prop);
        return;
    }
    if(b >= i && e <= j) {
        tree[node].sum += (e - b + 1) * (tree[node].prop + newVal);
        propagate(node, b, e, tree[node].prop + newVal);
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    propagate(node, b, e, tree[node].prop);
    update(left, b, mid, i, j, newVal);
    update(right, mid + 1, e, i, j, newVal);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

long long query(int node, int b, int e, int i, int j) {
    if(i > e || j < b) return 0;
    if(b >= i && e <= j) {
        return tree[node].sum + (e - b + 1) * tree[node].prop;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    tree[node].sum += (e - b + 1) * tree[node].prop;
    propagate(node, b, e, tree[node].prop);
    long long lQuery = query(left, b, mid, i, j);
    long long rQuery = query(right, mid + 1, e, i, j);
    return lQuery + rQuery;
}

void propagate(int node, int b, int e, long long prop) {
    if(b != e) {
        int left = 2 * node;
        int right = left + 1;
        tree[left].prop += prop;
        tree[right].prop += prop;
    }
    tree[node].prop = 0;
}
