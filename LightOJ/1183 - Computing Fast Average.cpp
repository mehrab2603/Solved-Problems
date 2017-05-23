#include<bits/stdc++.h>
#define MAX 100010

using namespace std;
int arr[MAX];

struct Node {
    int value, prop;
} tree[4 * MAX];

void build(int, int, int);
void propagate(int, int, int);
void update(int, int, int, int, int, int);
int query(int, int, int, int, int);
int gcd (int, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n, q;
        scanf("%d %d", &n, &q);
        build(1, 0, n - 1);
        printf("Case %d:\n", ++caseno);
        while(q--) {
            int command;
            scanf("%d", &command);
            if(command == 1) {
                int i, j, v;
                scanf("%d %d %d", &i, &j, &v);
                update(1, 0, n - 1, i, j, v);
            }
            else {
                int i, j;
                scanf("%d %d", &i, &j);
                int sum = query(1, 0, n - 1, i, j);
                int number = j - i + 1;
                if(sum % number == 0)
                    printf("%d\n", sum / number);
                else {
                    int div = gcd(sum, number);
                    printf("%d/%d\n", sum / div, number / div);
                }
            }
        }
    }
    return 0;
}

void build(int node, int b, int e) {
    if(b == e) {
        tree[node].value = 0;
        tree[node].prop = -1;
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node].value = tree[left].value + tree[right].value;
    tree[node].prop = -1;
    return;
}

void update(int node, int b, int e, int i, int j, int newVal) {
    if(b > j || e < i) {
        propagate(node, b, e);
        return;
    }
    if(b >= i && e <= j) {
        tree[node].prop = newVal;
        propagate(node, b, e);
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    propagate(node, b, e);
    update(left, b, mid, i, j, newVal);
    update(right, mid + 1, e, i, j, newVal);
    tree[node].value = tree[left].value + tree[right].value;
}

int query(int node, int b, int e, int i, int j) {
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) {
        propagate(node, b, e);
        return tree[node].value;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    propagate(node, b, e);
    return query(left, b, mid, i, j) + query(right, mid + 1, e, i, j);
}

void propagate(int node, int b, int e) {
    if(b != e && tree[node].prop != -1) {
        int left = 2 * node;
        int right = left + 1;
        tree[left].prop = tree[node].prop;
        tree[right].prop = tree[node].prop;
    }
    if(tree[node].prop != -1) tree[node].value = (e - b + 1) * tree[node].prop;
    tree[node].prop = -1;
}

int gcd (int a, int b) {
  int c;
  while (a != 0) {
     c = a;
     a = b % a;
     b = c;
  }
  return b;
}
