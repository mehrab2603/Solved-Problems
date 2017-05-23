#include<bits/stdc++.h>
#define MAX 200010

using namespace std;

int tree[4 * MAX];
set < int > ans;

void propagate(int, int, int, int);
void update(int, int, int, int, int, int);
void query(int, int, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        memset(tree, 0, sizeof tree);
        for(int i = 0; i < n; i++) {
            int l, r;
            scanf("%d %d", &l, &r);
            update(1, 0, 2 * n - 1, l - 1, r - 1, i + 1);
        }
        ans.clear();
        query(1, 0, 2 * n - 1);
        printf("Case %d: %d\n", ++caseno, (int)ans.size());
    }
    return 0;
}

void update(int node, int b, int e, int i, int j, int color) {
    if(i > e || j < b) return;
    if(b >= i && e <= j) {
        propagate(node, b, e, color);
        tree[node] = color;
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    propagate(node, b, e, tree[node]);
    update(left, b, mid, i, j, color);
    update(right, mid + 1, e, i, j, color);
}

void query(int node, int b, int e) {
    if(tree[node]) {
        ans.insert(tree[node]);
        return;
    }
    if(b == e) return;
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    query(left, b, mid);
    query(right, mid + 1, e);
}

void propagate(int node, int b, int e, int prop) {
    if(b != e && tree[node]) {
        int left = 2 * node;
        int right = left + 1;
        tree[left] = prop;
        tree[right] = prop;
        tree[node] = 0;
    }
}
