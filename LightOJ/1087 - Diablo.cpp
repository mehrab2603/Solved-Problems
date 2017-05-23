#include<bits/stdc++.h>

using namespace std;

const int MAX = 150010;
int arr[MAX], tree[4 * MAX];

struct Query {
    char command;
    int value;
    Query(char command, int value) {this->command = command; this->value = value;}
};

vector< Query > queries;

void build(int, int, int, int);
void update(int, int, int, int, int);
int query(int, int, int, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        queries.clear();
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        getchar();
        int extra = 0;
        while(q--) {
            char command;
            int value;
            scanf("%c %d", &command, &value);
            getchar();
            if(command == 'a') {
                arr[n + extra++] = value;
            }
            queries.push_back(Query(command, value));
        }
        int last = n;
        n = n + extra;
        build(1, 0, n - 1, last);
        printf("Case %d:\n", ++caseno);
        for(int i = 0; i < (int)queries.size(); i++) {
            if(queries[i].command == 'a') {
                update(1, 0, n - 1, last++, 1);
            }
            else {
                int index = query(1, 0, n - 1, queries[i].value);
                if(index == -1) {printf("none\n"); continue;}
                update(1, 0, n - 1, index, 0);
                printf("%d\n", arr[index]);
            }
        }
    }
}

void build(int node, int b, int e, int last) {
    if(b == e) {
        if(b < last) tree[node] = 1;
        else tree[node] = 0;
        return;
    }
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    build(left, b, mid, last);
    build(right, mid + 1, e, last);
    tree[node] = tree[left] + tree[right];
}

void update(int node, int b, int e, int i, int val) {
    if(b > i || e < i) return;
    if(b >= i && e <= i) {
        tree[node] = val;
        return;
    }
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int sum) {
    if(b == e) return b;
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    if(tree[left] + tree[right] < sum) return -1;
    else if(tree[left] >= sum) return query(left, b, mid, sum);
    else if(tree[left] < sum) return query(right, mid + 1, e, sum - tree[left]);
}
