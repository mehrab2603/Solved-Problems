#include<bits/stdc++.h>

using namespace std;

int n, m;

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

vector< Edge > edge;
map< string, int > mymap;

int kruskal();

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        edge.clear();
        mymap.clear();
        scanf("%d", &m);
        getchar();
        int counter = 0;
        char city1[55], city2[55];
        int cost;
        for(int i = 0; i < m; i++) {
            scanf("%s %s %d", city1, city2, &cost);
            getchar();
            if(mymap.find(city1) == mymap.end()) mymap[city1] = counter++;
            if(mymap.find(city2) == mymap.end()) mymap[city2] = counter++;
            edge.push_back(Edge(mymap[city1], mymap[city2], cost));
        }
        n = counter;
        printf("Case %d: ", ++caseno);
        int ans = kruskal();
        if(ans == -1) printf("Impossible\n");
        else printf("%d\n", ans);
    }
    return 0;
}

int kruskal() {
    sort(edge.begin(), edge.end());
    DisjointSet ds(n);
    int counter = 0, sum = 0;
    for(int i = 0; i < (int)edge.size(); i++) {
        Edge currentEdge = edge[i];
        if(!ds.isSameSet(currentEdge.u, currentEdge.v)) {
            ds.unionSet(currentEdge.u, currentEdge.v);
            sum += currentEdge.w;
            counter++;
            if(counter == n - 1) break;
        }
    }
    if(counter < n - 1) sum = -1;
    return sum;
}

