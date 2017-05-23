#include<bits/stdc++.h>
#define MAX 1024010

using namespace std;

int arr[MAX];
struct Node {
    int value, prop;
} tree[4 * MAX];

void propagate(int, int, int);
void build(int, int, int);
void update(int, int, int, int, int, int);
int query(int, int, int, int, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int m;
        scanf("%d", &m);
        int pos = 0;
        for(int i = 0; i < m; i++) {
            int T;
            scanf("%d", &T);
            char pirates[55];
            getchar();
            scanf("%s", pirates);
            int len = strlen(pirates);
            for(int j = 0; j < T; j++)
                for(int k = 0; k < len; k++)
                    arr[pos++] = pirates[k] - '0';
        }
        build(1, 0, pos - 1);
        int q, qno = 0;
        scanf("%d", &q);
        getchar();
        printf("Case %d:\n", ++caseno);
        while(q--) {
            char ch;
            int a, b;
            scanf("%c %d %d", &ch, &a, &b);
            getchar();
            if(ch == 'F') update(1, 0, pos - 1, a, b, 1);
            else if(ch == 'E') update(1, 0, pos - 1, a, b, 2);
            else if(ch == 'I') update(1, 0, pos - 1, a, b, 3);
            else printf("Q%d: %d\n", ++qno, query(1, 0, pos - 1, a, b));
        }
    }
    return 0;
}

void build(int node, int b, int e) {
    if(b == e) {
        tree[node].value = arr[b];
        tree[node].prop = 0;
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node].value = tree[left].value + tree[right].value;
    tree[node].prop = 0;
}

void update(int node, int b, int e, int i, int j, int newVal) {
    propagate(node, b, e);
    if(b > j || e < i) return;
    else if(b >= i && e <= j) {
        tree[node].prop = newVal;
        propagate(node, b, e);
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    update(left, b, mid, i, j, newVal);
    update(right, mid + 1, e, i, j, newVal);
    tree[node].value = tree[left].value + tree[right].value;
}

void propagate(int node, int b, int e) {
    if(b != e && tree[node].prop != 0) {
        int left = 2 * node;
        int right = left + 1;
        if(tree[node].prop != 3) {
            tree[left].prop = tree[node].prop;
            tree[right].prop = tree[node].prop;
        }
        else if(tree[node].prop == 3){
            if(tree[left].prop == 0) tree[left].prop = 3;
            else if(tree[left].prop == 3) tree[left].prop = 0;
            else if(tree[left].prop == 1) tree[left].prop = 2;
            else tree[left].prop = 1;
            if(tree[right].prop == 0) tree[right].prop = 3;
            else if(tree[right].prop == 3) tree[right].prop = 0;
            else if(tree[right].prop == 1) tree[right].prop = 2;
            else tree[right].prop = 1;
        }
    }
    if(tree[node].prop == 1)
        tree[node].value = e - b + 1;
    else if(tree[node].prop == 2)
        tree[node].value = 0;
    else if(tree[node].prop == 3)
        tree[node].value = (e - b + 1) - tree[node].value;
    tree[node].prop = 0;
}

int query(int node, int b, int e, int i, int j) {
    propagate(node, b, e);
    if(b > j || e < i) return 0;
    else if(b >= i && e <= j)
        return tree[node].value;
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    return query(left, b, mid, i, j) + query(right, mid + 1, e, i, j);
}

