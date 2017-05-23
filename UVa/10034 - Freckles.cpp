#include<bits/stdc++.h>

using namespace std;

struct Coordinate {
    int number;
    double x, y;
    Coordinate() {}
    Coordinate(double a, double b, int c) {x = a; y = b; number = c;}
};

struct Edge {
    Coordinate a, b;
    double dist;
    Edge() {}
    Edge(Coordinate x, Coordinate y, double z) {a = x; b = y; dist = z;}
    bool operator<(const Edge &e) const {return dist < e.dist;}
};

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

double distanceCalculator(double, double, double, double);
double kruskal(int);

Coordinate input[110];
vector < Edge > edge;

int main() {
    int t;
    scanf("%d", &t);
    bool flag = false;
    while(t--) {
        if(flag) printf("\n");
        else flag = true;
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            double x, y;
            scanf("%lf %lf", &x, &y);
            input[i] = Coordinate(x, y, i);
        }
        edge.clear();
        for(int i = 0; i < n; i++) {
            Coordinate one = input[i];
            for(int j = i + 1; j < n; j++) {
                Coordinate two = input[j];
                double dist = distanceCalculator(one.x, one.y, two.x, two.y);
                edge.push_back(Edge(one, two, dist));
            }
        }
        printf("%.2lf\n", kruskal(n));
    }
    return 0;
}

double distanceCalculator(double a1, double b1, double a2, double b2) {
    return sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
}

double kruskal(int n) {
    sort(edge.begin(), edge.end());
    DisjointSet ds(n);
    double ans = 0;
    int counter = 0;
    for(int i = 0; i < (int)edge.size(); i++) {
        if(!ds.isSameSet(edge[i].a.number, edge[i].b.number)) {
            ds.unionSet(edge[i].a.number, edge[i].b.number);
            ans += edge[i].dist;
            counter++;
            if(counter == n - 1) break;
        }
    }
    return ans;
}
