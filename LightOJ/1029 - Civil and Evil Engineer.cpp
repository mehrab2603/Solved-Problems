#include<bits/stdc++.h>

using namespace std;

int n;

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
};

struct Compare {
    bool operator()(Edge e1, Edge e2) {return e1.w < e2.w;}
};


vector< Edge > edge;

int kruskal();

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        edge.clear();
        scanf("%d", &n);
        int u, v, w;
        while(scanf("%d %d %d", &u, &v, &w) && (u || v || w))
            edge.push_back(Edge(u, v, w));
        int ans = kruskal();
        printf("Case %d: ", ++caseno);
        if(ans % 2 == 0) printf("%d\n", ans / 2);
        else printf("%d/2\n", ans);
    }
    return 0;
}

int kruskal() {
    sort(edge.begin(), edge.end(), Compare());
    DisjointSet ds(n + 1);
    int counter = 0, sum = 0;
    for(int i = 0; i < (int)edge.size(); i++) {
        Edge currentEdge = edge[i];
        if(!ds.isSameSet(currentEdge.u, currentEdge.v)) {
            ds.unionSet(currentEdge.u, currentEdge.v);
            sum += currentEdge.w;
            counter++;
            if(counter == n) break;
        }
    }
    DisjointSet ds2(n + 1);
    counter = 0;
    for(int i = (int)edge.size() - 1; i >= 0; i--) {
        Edge currentEdge = edge[i];
        if(!ds2.isSameSet(currentEdge.u, currentEdge.v)) {
            ds2.unionSet(currentEdge.u, currentEdge.v);
            sum += currentEdge.w;
            counter++;
            if(counter == n) break;
        }
    }
    return sum;
}


