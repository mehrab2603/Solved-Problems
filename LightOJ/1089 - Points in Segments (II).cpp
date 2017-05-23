#include<bits/stdc++.h>

using namespace std;

const int MAX = 2 * 50000 + 50010;

map< int, int > mymap;

struct Segment {
    int l, r;
    Segment(int l, int r) {this->l = l; this->r = r;}
};

struct Node {
    int value, propagate;
} tree[4 * MAX];

vector< Segment > segment;
vector< int > point, input;

void build(int, int, int);
void update(int, int, int, int, int);
int query(int, int, int, int);
void propagate(int, int, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        mymap.clear();
        segment.clear();
        point.clear();
        input.clear();
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++) {
            int l, r;
            scanf("%d %d", &l, &r);
            segment.push_back(Segment(l, r));
            input.push_back(l);
            input.push_back(r);
        }
        for(int i = 0; i < q; i++) {
            int x;
            scanf("%d", &x);
            point.push_back(x);
            input.push_back(x);
        }
        sort(input.begin(), input.end());
        int counter = 0;
        for(int i = 0; i < (int)input.size(); i++)
            if(mymap.find(input[i]) == mymap.end())
                mymap[input[i]] = counter++;
        int maxR = INT_MIN;
        for(int i = 0; i < (int)segment.size(); i++) {
            segment[i].l = mymap[segment[i].l], segment[i].r = mymap[segment[i].r];
            if(segment[i].r > maxR) maxR = segment[i].r;
        }
        for(int i = 0; i < (int)point.size(); i++)
            point[i] = mymap[point[i]];
        build(1, 0, maxR);
        for(int i = 0; i < (int)segment.size(); i++) update(1, 0, maxR, segment[i].l, segment[i].r);
        printf("Case %d:\n", ++caseno);
        for(int i = 0; i < (int)point.size(); i++) point[i] > maxR ? printf("0\n") : printf("%d\n", query(1, 0, maxR, point[i]));
    }
}

void build(int node, int b, int e) {
    if(b == e) {
        tree[node].value = 0;
        tree[node].propagate = 0;
        return;
    }
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node].value = 0;
    tree[node].propagate = 0;
}

void update(int node, int b, int e, int i, int j) {
    propagate(node, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
        tree[node].propagate++;
        propagate(node, b, e);
        return;
    }
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    update(left, b, mid, i, j);
    update(right, mid + 1, e, i, j);
    tree[node].value = tree[left].value + tree[right].value;
}

int query(int node, int b, int e, int i) {
    propagate(node, b, e);
    if(b > i || e < i) return -1;
    if(b >= i && e <= i) return tree[node].value;
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    int lq = query(left, b, mid, i), rq = query(right, mid + 1, e, i);
    return lq == -1 ? rq : lq;
}

void propagate(int node, int b, int e) {
    if(tree[node].propagate == 0) return;
    if(b != e) {
        int left = 2 * node, right = left + 1;
        tree[left].propagate += tree[node].propagate;
        tree[right].propagate += tree[node].propagate;
    }
    tree[node].value += (e - b + 1) * tree[node].propagate;
    tree[node].propagate = 0;
}
