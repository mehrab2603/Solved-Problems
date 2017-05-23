#include<bits/stdc++.h>
#define MAX 760

using namespace std;

bool exists[MAX][MAX];

struct DisjointSet {
    vector<int> par, ran;
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

struct Building {
    int x, y;
    Building(int x, int y) {this->x = x; this->y = y;}
};

struct Edge {
    int u, v, cost;
    Edge(int u, int v, int cost) {this->u = u; this->v = v; this->cost = cost;}
    bool operator<(const Edge &e) const {return cost < e.cost;}
};

vector< Building > buildings;
vector< Edge > edges;

double kruskal(int);

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        buildings.clear();
        edges.clear();
        memset(exists, false,sizeof exists);
        for(int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            buildings.push_back(Building(x, y));
        }
        int m;
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            int b1, b2;
            scanf("%d %d", &b1, &b2);
            b1--, b2--;
            exists[b1][b2] = true;
            exists[b2][b1] = true;
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int dist;
                if(exists[i][j]) dist = 0;
                else dist = (buildings[i].x - buildings[j].x) * (buildings[i].x - buildings[j].x) + (buildings[i].y - buildings[j].y) * (buildings[i].y - buildings[j].y);
                edges.push_back(Edge(i, j, dist));
            }
        }
        printf("%.2lf\n", kruskal(n));
    }
}

double kruskal(int n) {
    sort(edges.begin(), edges.end());
    int counter = 0;
    double sum = 0;
    DisjointSet ds(n);
    for(int i = 0; i < (int)edges.size(); i++) {
        Edge edge = edges[i];
        if(!ds.isSameSet(edge.u, edge.v)) {
            ds.unionSet(edge.u, edge.v);
            sum += sqrt(edge.cost);
            counter++;
            if(counter == n - 1) break;
        }
    }
    return sum;
}
