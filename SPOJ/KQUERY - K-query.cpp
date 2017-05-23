#include <bits/stdc++.h>

using namespace std;

int tree[4 * 30010], ans[200010];

void build(int, int, int);
void update(int, int, int, int, int);
int queryans(int, int, int, int, int);

struct Query {
    int i, j, k, number;
    Query() {}
    Query(int a, int b, int c, int d) {i = a; j = b; k = c; number = d;}
};

struct Input {
    int input, number;
    Input() {}
    Input(int a, int b) {input = a; number = b;}
};

struct QueryCompare {
    bool operator()(Query a, Query b) {return a.k < b.k;}
};

struct InputCompare {
    bool operator()(Input a, Input b) {return a.input < b.input;}
};

Query query[200010];
Input input[30010];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        input[i] = Input(x, i);
    }
    sort(input, input + n, InputCompare());
    int q;
    scanf("%d", &q);
    for(int l = 0; l < q; l++) {
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);
        query[l] = Query(i, j, k, l);
    }
    build(1, 0, n - 1);
    sort(query, query + q, QueryCompare());
    int index = 0;
    for(int i = 0; i < q; i++) {
        while(input[index].input <= query[i].k && index < n) {
            update(1, 0, n - 1, input[index].number, 0);
            index++;
        }
        ans[query[i].number] = queryans(1, 0, n - 1, query[i].i - 1, query[i].j - 1);
    }
    for(int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}

void build(int node, int b, int e) {
    if(b == e) {
        tree[node] = 1;
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
}

void update(int node, int b, int e, int i, int newVal) {
    if(i > e || i < b) return;
    if(b >= i && e <= i) {
        tree[node] = newVal;
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    update(left, b, mid, i, newVal);
    update(right, mid + 1, e, i, newVal);
    tree[node] = tree[left] + tree[right];
}

int queryans(int node, int b, int e, int i, int j) {
    if(i > e || j < b) return 0;
    if(b >= i && e <= j) {
        return tree[node];
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    return queryans(left, b, mid, i, j) + queryans(right, mid + 1, e, i, j);
}
