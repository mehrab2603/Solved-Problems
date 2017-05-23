#include<bits/stdc++.h>
#define MAX 100010

using namespace std;

int arr[MAX];

struct Node {
    int value;
} tree[4 * MAX];

int query(int, int, int, int, int);
void update(int, int, int, int, int);
void build(int, int, int);

int main() {
    int n, k;
    while(scanf("%d %d", &n ,&k) != EOF) {
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        getchar();
        build(1, 0, n - 1);
        for(int i = 0; i < k; i++) {
            char ch;
            int a, b;
            scanf("%c %d %d", &ch, &a, &b);
            getchar();
            if(ch == 'C') {
                update(1, 0, n - 1, a - 1, b);
            }
            else if(ch == 'P'){
                int qValue = query(1, 0, n - 1, a - 1, b - 1);
                if(qValue > 0) printf("+");
                else if(qValue < 0) printf("-");
                else if(qValue == 0) printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}

void build(int node, int b, int e) {
    if(b == e) {
        if(arr[b] == 0)
            tree[node].value = 0;
        else if(arr[b] < 0)
            tree[node].value = -1;
        else if(arr[b] > 0)
            tree[node].value = 1;
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node].value = tree[left].value * tree[right].value;
}

void update(int node, int b, int e, int i, int newValue) {
    if(i > e || i < b) return;
    if(b >= i && e <= i) {
        if(newValue < 0)
            tree[node].value = -1;
        else if(newValue == 0)
            tree[node].value = 0;
        else if(newValue > 0)
            tree[node].value = 1;
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    update(left, b, mid, i, newValue);
    update(right, mid + 1, e, i, newValue);
    tree[node].value = tree[left].value * tree[right].value;
}

int query(int node, int b, int e, int i, int j) {
    if(i > e || j < b) return 1;
    if(b >= i && e <= j) {
        return tree[node].value;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    return query(left, b, mid, i, j) * query(right, mid + 1, e, i, j);
}
