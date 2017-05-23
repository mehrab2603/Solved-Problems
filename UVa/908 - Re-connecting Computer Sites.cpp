#include<bits/stdc++.h>

using namespace std;
int n, t, k;
long long m;

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
    int u, v, w;
    Edge() {}
    Edge(int a, int b, int c) {u = a; v = b; w = c;}
    bool operator<(const Edge &e) const {return w < e.w;}
};

Edge tLines[1000020];

long long kruskal();

int main() {
    bool flag = false;
    while(scanf("%d", &n) != EOF) {
        if(flag) printf("\n");
        else flag = true;
        long long ans1 = 0;
        for(int i = 0; i < n - 1; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            tLines[i] = Edge(u, v, w);
            ans1 += w;
        }
        scanf("%d", &t);
        for(int i = 0; i < t; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            tLines[n - 1 + i] = Edge(u, v, w);
        }
        scanf("%lld", &m);
        for(long long i = 0; i < m; i++) {
            int x;
            scanf("%d %d %d", &x, &x, &x);
        }
        printf("%lld\n%lld\n", ans1, kruskal());
    }
}

long long kruskal() {
    sort(tLines, tLines + n + k);
    DisjointSet ds(n + 1);
    int counter = 0;
    long long ans = 0;
    for(int i = 0; i < n + k; i++) {
        Edge currentEdge = tLines[i];
        if(!ds.isSameSet(currentEdge.u, currentEdge.v)) {
            ds.unionSet(currentEdge.u, currentEdge.v);
            ans += currentEdge.w;
            counter++;
            if(counter == n - 1) break;
        }
    }
    return ans;
}
