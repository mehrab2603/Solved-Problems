#include <bits/stdc++.h>
#define MAX 100010

using namespace std;

int n, d, arr[MAX], treeMax[4 * MAX], treeMin[4 * MAX];

void buildMax(int, int, int);
void buildMin(int, int, int);
int queryMax(int, int, int, int, int);
int queryMin(int, int, int, int, int);

int main() {
    freopen("input.txt", "r", stdin);
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &d);
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        buildMax(1, 0, n - 1);
        buildMin(1, 0, n - 1);
        int ans = -INT_MAX;
        for(int i = 0; i + d - 1 < n; i++) {
            int maximum = queryMax(1, 0, n - 1, i, i + d - 1);
            int minimum = queryMin(1, 0, n - 1, i, i + d - 1);
            ans = max(ans, maximum - minimum);
        }
        printf("Case %d: %d\n", ++caseno, ans);
    }
    return 0;
}

void buildMax(int node, int b, int e) {
    if(b == e) {
        treeMax[node] = arr[b];
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    buildMax(left, b, mid);
    buildMax(right, mid + 1, e);
    treeMax[node] = max(treeMax[left], treeMax[right]);
}

void buildMin(int node, int b, int e) {
    if(b == e) {
        treeMin[node] = arr[b];
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    buildMin(left, b, mid);
    buildMin(right, mid + 1, e);
    treeMin[node] = min(treeMin[left], treeMin[right]);
}

int queryMax(int node, int b, int e, int i, int j) {
    if(i > e || j < b) return -1;
    if(b >= i && e <= j) {
        return treeMax[node];
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    int lq = queryMax(left, b, mid, i, j);
    int rq = queryMax(right, mid + 1, e, i, j);
    return max(lq, rq);
}

int queryMin(int node, int b, int e, int i, int j) {
    if(i > e || j < b) return INT_MAX;
    if(b >= i && e <= j) {
        return treeMin[node];
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    int lq = queryMin(left, b, mid, i, j);
    int rq = queryMin(right, mid + 1, e, i, j);
    return min(lq, rq);
}
