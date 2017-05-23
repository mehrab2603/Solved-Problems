#include<bits/stdc++.h>
#define MAX 100010

using namespace std;

int arr[MAX], counter[MAX], started[MAX], ended[MAX], tree[4 * MAX];
void build(int, int, int);
int query(int, int, int, int, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        memset(counter, 0, sizeof counter);
        memset(started, -1, sizeof started);
        int n, c, q;
        scanf("%d %d %d", &n, &c, &q);
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            counter[arr[i]]++;
            if(started[arr[i]] == -1) started[arr[i]] = i;
            ended[arr[i]] = i;
        }
        build(1, 0, n - 1);
        printf("Case %d:\n", ++caseno);
        while(q--) {
            int i, j;
            scanf("%d %d", &i, &j);
            i--, j--;
            if(arr[i] == arr[j]) printf("%d\n", j - i + 1);
            else {
                int ans = max(ended[arr[i]] - i + 1, j - started[arr[j]] + 1);
                if(ended[arr[i]] + 1 <= started[arr[j]] - 1)
                    ans = max(ans, query(1, 0, n - 1, ended[arr[i]] + 1, started[arr[j]] - 1));
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}

void build(int node, int b, int e) {
    if(b == e) {
        tree[node] = counter[arr[b]];
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node] = max(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j) {
    if(i > e || j < b) return -9999;
    if(b >= i && e <= j)
        return tree[node];
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    return max(query(left, b, mid, i, j), query(right, mid + 1, e, i, j));
}
