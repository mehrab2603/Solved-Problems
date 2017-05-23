#include<bits/stdc++.h>
#define MAX 100010

using namespace std;

char input[MAX];
int tree[4 * MAX];

void build(int, int, int);
void update(int, int, int, int, int);
void propagate(int, int, int);
int query(int, int, int, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    getchar();
    while(t--) {
        char ch;
        int counter = 0;
        while(scanf("%c", &ch) && ch!= '\n')
            input[counter++] = ch;
        build(1, 0, counter - 1);
        int q;
        scanf("%d", &q);
        getchar();
        printf("Case %d:\n", ++caseno);
        while(q--) {
            char command;
            scanf("%c", &command);
            if(command == 'I') {
                int i, j;
                scanf("%d %d", &i, &j);
                getchar();
                update(1, 0, counter - 1, i - 1, j - 1);
            }
            else {
                int i;
                scanf("%d", &i);
                getchar();
                if(query(1, 0, counter - 1, i - 1) % 2 == 0)
                    printf("%c\n", input[i - 1]);
                else {
                    if(input[i - 1] == '0') printf("1\n");
                    else printf("0\n");
                }
            }
        }
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
    tree[node] = 0;
}

void update(int node, int b, int e, int i, int j) {
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
        tree[node]++;
        return;
    }
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    propagate(node, b, e);
    update(left, b, mid, i, j);
    update(right, mid + 1, e, i, j);
}

int query(int node, int b, int e, int pos) {
    if(pos > e || pos < b) return -1;
    if(b >= pos && e <= pos)
        return tree[node];
    int left = 2 * node;
    int right = left + 1;
    int mid = (b + e) / 2;
    propagate(node, b, e);
    int lq = query(left, b, mid, pos), rq = query(right, mid + 1, e, pos);
    if(lq == -1) return rq;
    else return lq;
}

void propagate(int node, int b, int e) {
    if(b != e && tree[node]) {
        int left = 2 * node;
        int right = left + 1;
        tree[left] += tree[node];
        tree[right] += tree[node];
        tree[node] = 0;
    }
}
