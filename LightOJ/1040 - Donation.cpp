#include<bits/stdc++.h>

using namespace std;
int n, mat[55][55];

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
    int u, v, length;
    Edge() {}
    Edge(int a, int b, int c) {u = a; v = b; length = c;}
    bool operator<(const Edge &e) const {return length < e.length;}
};

vector< Edge > edge;

int kruskal();

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        edge.clear();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int length;
                scanf("%d", &length);
                if(length) edge.push_back(Edge(i, j, length));
            }
        }
        printf("Case %d: %d\n", ++caseno, kruskal());
    }
    return 0;
}

int kruskal() {
    sort(edge.begin(), edge.end());
    DisjointSet ds(n);
    int ans = 0, counter = 0;
    for(int i = 0; i < (int)edge.size(); i++) {
        Edge currentEdge = edge[i];
        if(!ds.isSameSet(currentEdge.u, currentEdge.v) && counter < n - 1) {
            ds.unionSet(currentEdge.u, currentEdge.v);
            counter++;
        }
        else {
            ans += currentEdge.length;
        }
    }
    if(counter < n - 1) ans = -1;
    return ans;
}
