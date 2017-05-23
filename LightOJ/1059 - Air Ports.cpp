#include<bits/stdc++.h>

using namespace std;

int n, m, a, ans1, ans2;

class DisjointSet {
private:
    vector<int> par, ran;
public:
    DisjointSet(int n) {
        par.assign(n, 0);
        ran.assign(n, 0);
        for(int i = 0; i < n; i++)
            par[i] = i;
    }

    int findSet(int x) {
        return (par[x] == x) ? x : par[x] = findSet(par[x]);
    }

    bool isSameSet(int x, int y) {
        return findSet(x) == findSet(y);
    }

    void unionSet(int x, int y) {
        if(!isSameSet(x, y)) {
            int parX = par[x], parY = par[y];
            if(ran[parX] > ran[parY]) par[parY] = parX;
            else {
                par[parX] = parY;
                if(ran[parX] == ran[parY])
                    ran[parY]++;
            }
        }
    }
};

struct Edge {
    int x, y, c;
    Edge() {}
    Edge(int a, int b, int w) {x = a; y = b; c = w;}
    bool operator<(const Edge &e) const {return c < e.c;}
} edge[100010];

void kruskal();

int main() {
    //freopen("input.txt", "r", stdin);
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &m, &a);
        for(int i = 0; i < m; i++) {
            int x, y, c;
            scanf("%d %d %d", &x, &y, &c);
            edge[i] = Edge(x, y, c);
        }
        kruskal();
        printf("Case %d: %d %d\n", ++caseno, ans1, ans2);
    }
    return 0;
}

void kruskal() {
    sort(edge, edge + m);
    DisjointSet ds(n + 1);
    ans1 = a, ans2 = 1;
    int counter = 0;
    for(int i = 0; i < m; i++) {
        Edge currentEdge = edge[i];
        if(!ds.isSameSet(currentEdge.x, currentEdge.y)) {
            ds.unionSet(currentEdge.x, currentEdge.y);
            if(currentEdge.c >= a) {ans2++; ans1 += a;}
            else ans1 += currentEdge.c;
            counter++;
            if(counter == n - 1) break;
        }
    }
    ans1 += ((n - 1) - counter) * a;
    ans2 += (n - 1) - counter;
}
