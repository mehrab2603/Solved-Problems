#include<bits/stdc++.h>
#define MAX 2010

using namespace std;

int n, m, arr[MAX][MAX], mat[MAX][MAX], tree[4 * MAX];

void build(int, int, int, int);
int query(int, int, int, int, int, int);
int func(int, int, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &m, &n);
        getchar();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                char ch;
                scanf("%c", &ch);
                arr[i][j] = ch - '0';
            }
            getchar();
        }
        for(int i = 0; i < n; i++) {
            if(!arr[0][i])
                mat[0][i] = 1;
            else
                mat[0][i] = 0;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!arr[i][j])
                    mat[i][j] = mat[i - 1][j] + 1;
                else
                    mat[i][j] = 0;
            }
        }
        int ans = -1;
        for(int i = 0; i < m; i++) {
            build(1, 0, n - 1, i);
            ans = max(ans, func(0, n - 1, i));
        }
        printf("Case %d: %d\n", ++caseno, ans);

    }
    return 0;
}

void build(int node, int b, int e, int row) {
    if(b == e) {
        tree[node] = b;
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    build(left, b, mid, row);
    build(right, mid + 1, e, row);
    if(mat[row][tree[left]] < mat[row][tree[right]])
        tree[node] = tree[left];
    else
        tree[node] = tree[right];
}

int query(int node, int b, int e, int i, int j, int row) {
    if(b > j || e < i) return -1;
    if(b >= i && e <= j) return tree[node];
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    int lq = query(left, b, mid, i, j, row), rq = query(right, mid + 1, e, i, j, row);
    if(lq == -1) return rq;
    else if(rq == -1) return lq;
    else if(mat[row][lq] < mat[row][rq]) return lq;
    else return rq;
}

int func(int i, int j, int row) {
    if(i < 0 || i >= n || j < 0 || j >= n || i > j) return -INT_MAX;
    if(i == j) return mat[row][i];
    int lo = query(1, 0, n - 1, i, j, row);
    return max((j - i + 1) * mat[row][lo], max(func(i, lo - 1, row), func(lo + 1, j, row)));
}
