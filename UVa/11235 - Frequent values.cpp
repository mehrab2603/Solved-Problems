#include <bits/stdc++.h>
#define MAX 100010

using namespace std;

int input[MAX], tree[4 * MAX];
map<int, int> counter, start;
void init(int, int, int);
int query(int, int, int, int, int);

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        int q;
        scanf("%d", &q);
        counter.clear();
        start.clear();
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            input[i] = x;
            if(start.find(x) == start.end())
                start[x] = i;
            counter[x]++;
        }
        init(1, 0, n - 1);
        for(int i = 0; i < q; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--, b--;
            if(input[a] == input[b]) {
                printf("%d\n", b - a + 1);
            }
            else {
                int ans = max(counter[input[a]] - (a - start[input[a]]), b - start[input[b]] + 1);
                int left = start[input[a]] + counter[input[a]];
                int right = start[input[b]] - 1;
                if(left <= right) {
                    ans = max(ans, query(1, 0, n - 1, left, right));
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}


void init(int node, int b, int e) {
    if(b == e) {
        tree[node] = counter[input[b]];
        return;
    }
    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (b + e) / 2;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node] = max(tree[left], tree[right]);
    return;
}

int query(int node, int b, int e, int i, int j) {
    if(i > e || j < b) return -999;
    if(b >= i && e <= j) {
        return tree[node];
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    int leftQuery = query(left, b, mid, i, j);
    int rightQuery = query(right, mid + 1, e, i, j);
    return max(leftQuery, rightQuery);
}
