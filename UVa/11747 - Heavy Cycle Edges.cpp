#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
private:
    vector<int> par, ran, siz;
public:
    DisjointSet(int n) {
        par.assign(n, 0);
        ran.assign(n, 0);
        siz.assign(n, 1);
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
            if(ran[parX] > ran[parY]) par[parY] = parX, siz[parX] += siz[parY];
            else {
                par[parX] = parY;
                siz[parY] += siz[parX];
                if(ran[parX] == ran[parY])
                    ran[parY]++;
            }
        }
    }

    int getSize(int x) {
        return siz[findSet(x)];
    }
};

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
    bool operator<(const Edge& e) const {return w < e.w;}
};

vector< Edge > edges;
vector< int > ans;

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) && (n || m)) {
        edges.clear();
        ans.clear();
        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edges.push_back(Edge(u, v, w));
        }
        sort(edges.begin(), edges.end());
        DisjointSet ds(n);
        for(int i = 0; i < m; i++) {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if(!ds.isSameSet(u, v)) ds.unionSet(u, v);
            else ans.push_back(w);
        }
        if(ans.size() == 0) printf("forest\n");
        else {
            bool start = false;
            for(int i = 0; i < (int)ans.size(); i++) {
                if(!start) start = true;
                else printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
