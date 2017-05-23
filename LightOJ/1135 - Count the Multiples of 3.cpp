#include<bits/stdc++.h>
#define MAX 100010

using namespace std;

int arr[MAX];
struct Node {
    int zero, one, two, prop;
} tree[4 * MAX];

void build(int, int, int);
void update(int, int, int, int, int);
void propagate(int, int, int);
int query(int, int, int, int, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n, q;
        scanf("%d %d", &n, &q);
        memset(arr, 0, sizeof arr);
        build(1, 0, n - 1);
        printf("Case %d:\n", ++caseno);
        while(q--) {
            int command, i, j;
            scanf("%d %d %d", &command, &i, &j);
            if(command == 0)
                update(1, 0, n - 1, i, j);
            else
                printf("%d\n", query(1, 0, n - 1, i, j));
        }
    }
    return 0;
}

void build(int node, int b, int e) {
    if(b == e) {
        tree[node].zero = 1;
        tree[node].one = 0;
        tree[node].two = 0;
        tree[node].prop = 0;
        return;
    }
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node].zero = tree[left].zero + tree[right].zero;
    tree[node].one = tree[left].one + tree[right].one;
    tree[node].two = tree[left].two + tree[right].two;
    tree[node].prop = 0;
}

void update(int node, int b, int e, int i, int j) {
    if(tree[node].prop) propagate(node, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
        tree[node].prop++;
        propagate(node, b, e);
        return;
    }
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    update(left, b, mid, i, j);
    update(right, mid + 1, e, i, j);
    tree[node].zero = tree[left].zero + tree[right].zero;
    tree[node].one = tree[left].one + tree[right].one;
    tree[node].two = tree[left].two + tree[right].two;
}

void propagate(int node, int b, int e) {
    if(b != e && tree[node].prop != 0) {
        int left = 2 * node, right = left + 1;
        tree[left].prop += tree[node].prop;
        tree[right].prop += tree[node].prop;
    }
    if(tree[node].prop % 3 == 1) {
        int temp = tree[node].one;
        tree[node].one = tree[node].zero;
        tree[node].zero = tree[node].two;
        tree[node].two = temp;
    }
    else if(tree[node].prop % 3 == 2) {
        int temp = tree[node].zero;
        tree[node].zero = tree[node].one;
        tree[node].one = tree[node].two;
        tree[node].two = temp;
    }
    tree[node].prop = 0;
}

int query(int node, int b, int e, int i, int j) {
    if(tree[node].prop) propagate(node, b, e);
    if(b > j || e < i) return 0;
    if(b >= i && e <= j)
        return tree[node].zero;
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    return query(left, b, mid, i, j) + query(right, mid + 1, e, i, j);
}
