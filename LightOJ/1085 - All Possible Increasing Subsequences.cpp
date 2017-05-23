#include<bits/stdc++.h>
#define MAX 100010
#define MOD 1000000007

using namespace std;

int arr[MAX], iss[MAX], tree[4 * MAX];
struct Input {
    int input, index;
    Input() {}
    Input(int a, int b) {input = a, index = b;}
};
vector <Input> sorted;

void build(int, int, int);
void update(int, int, int, int, int);
int query(int, int, int, int, int);
int binarySearch(int, int, Input);

struct Compare {
    bool operator()(Input a, Input b) {
        if(a.input < b.input)
            return true;
        else if(a.input == b.input)
            return a.index > b.index;
        else
            return false;
    }
};

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            sorted.push_back(Input(arr[i], i));
        }
        sort(sorted.begin(), sorted.end(), Compare());
        build(1, 0, n - 1);
        for(int i = 0; i < n; i++) {
            int index = binarySearch(0, n - 1, Input(arr[i], i));
            int iss = query(1, 0, n - 1, 0, index) + 1;
            update(1, 0, n - 1, index, iss);
        }
        printf("Case %d: %d\n", ++caseno, tree[1]);
        sorted.clear();
    }
    return 0;
}

void build(int node, int b, int e) {
    if(b == e) {
        tree[node] = 0;
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
}

void update(int node, int b, int e, int i, int newValue) {
    if(i > e || i < b) return;
    if(b == i && e == i) {
        tree[node] = newValue % MOD;
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    update(left, b, mid, i, newValue);
    update(right, mid + 1, e, i, newValue);
    tree[node] = (tree[left] + tree[right]) % MOD;

}

int query(int node, int b, int e, int i, int j) {
    if(i > e || j < b) return 0;
    else if(b >= i && e <= j) {
        return tree[node];
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    int lq = query(left, b, mid, i, j) % MOD;
    int rq = query(right, mid + 1, e, i, j) % MOD;
    return (lq + rq) % MOD;
}

int binarySearch(int b, int e, Input input) {
    int mid;
    while(b <= e) {
        mid = (b + e) / 2;
        if(sorted[mid].input == input.input) {
            if(sorted[mid].index == input.index)
                return mid;
            else if(sorted[mid].index > input.index)
                b = mid + 1;
            else
                e = mid - 1;

        }
        else if(sorted[mid].input > input.input) {
            e = mid - 1;
        }
        else {
            b = mid + 1;
        }
    }
    return -1;
}
