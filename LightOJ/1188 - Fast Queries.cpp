#include<bits/stdc++.h>
#define MAX 100010

using namespace std;

int arr[MAX], lastOf[MAX], pointTo[MAX], tree[4 * MAX];

struct Query {
    int i, j, number;
    Query(int i, int j, int number) {
        this->i = i;
        this->j = j;
        this->number = number;
    }
    bool operator<(const Query& q) const {return j > q.j;}
};

vector< Query > queries;
vector< int > ans;

void build(int, int, int);
void update(int, int, int, int);
int query(int, int, int, int, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        memset(lastOf, -1, sizeof lastOf);
        queries.clear();
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if(lastOf[x] == -1) {
                arr[i] = 1;
                pointTo[i] = -1;
                lastOf[x] = i;
            }
            else {
                arr[lastOf[x]] = 0;
                arr[i] = 1;
                pointTo[i] = lastOf[x];
                lastOf[x] = i;
            }
        }
        printf("Case %d:\n", ++caseno);
        int qnumber = 0;
        while(q--) {
            int i, j;
            scanf("%d %d", &i, &j);
            i--, j--;
            queries.push_back(Query(i, j, qnumber++));
        }
        sort(queries.begin(), queries.end());
        ans.assign((int)queries.size(), -1);
        build(1, 0, n - 1);
        int lastJ = n - 1;
        for(int i = 0; i < (int)queries.size(); i++) {
            if(queries[i].j != lastJ) {
                for(int k = lastJ; k > queries[i].j; k--)
                    if(pointTo[k] != -1) update(1, 0, n - 1, pointTo[k]);
                lastJ = queries[i].j;
            }
            ans[queries[i].number] = query(1, 0, n - 1, queries[i].i, queries[i].j);
        }
        for(int i = 0; i < (int)ans.size(); i++) printf("%d\n", ans[i]);
    }
    return 0;
}

void build(int node, int b, int e) {
    if(b == e) {
        tree[node] = arr[b];
        return;
    }
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
}

void update(int node, int b, int e, int i) {
    if(b > i || e < i) return;
    if(b >= i && e <= i) {
        tree[node] = 1;
        return;
    }
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    update(left, b, mid, i);
    update(right, mid + 1, e, i);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j) {
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) {
        return tree[node];
    }
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    return query(left, b, mid, i, j) + query(right, mid + 1, e, i, j);
}
