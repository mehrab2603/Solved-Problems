#include<bits/stdc++.h>

using namespace std;

int n, w, ans[6010];
bool nodeFlag[210];

class DisjointSet {
private:
    vector< int > par, ran;
public:
    DisjointSet(int n) {
        par.assign(n, 0);
        ran.assign(n, 0);
        for(int i = 0; i < n; i++)
            par[i] = i;
    }
    int findSet(int a) {return (par[a] == a) ? a : par[a] = findSet(par[a]);}
    bool isSameSet(int a, int b) {return findSet(a) == findSet(b);}
    void unionSet(int a, int b) {
        if(!isSameSet(a, b)) {
            int parA = par[a], parB = par[b];
            if(ran[parA] > ran[parB]) par[parB] = parA;
            else {
                par[parA] = parB;
                if(ran[parA] == ran[parB])
                    ran[parB]++;
            }
        }
    }
};

struct Trail {
    int u, v, l;
    Trail() {}
    Trail(int a, int b, int c) {u = a; v = b; l = c;}
    bool operator<(const Trail &t) const {return l < t.l;}
};

multiset< Trail > mytrail;

void kruskal(int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        mytrail.clear();
        memset(nodeFlag, false, sizeof nodeFlag);
        int nodeCount = 0;
        scanf("%d %d", &n, &w);
        for(int i = 0; i < w; i++) {
            int u, v, l;
            scanf("%d %d %d", &u, &v, &l);
            if(nodeCount < n) {
                if(!nodeFlag[u]) {nodeFlag[u] = true; nodeCount++;}
                if(!nodeFlag[v]) {nodeFlag[v] = true; nodeCount++;}
                mytrail.insert(Trail(u, v, l));
                if(nodeCount >= n) kruskal(i);
                else ans[i] = -1;
                continue;
            }
            mytrail.insert(Trail(u, v, l));
            kruskal(i);
        }
        printf("Case %d:\n", ++caseno);
        for(int i = 0; i < w; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}

void kruskal(int week) {
    multiset< Trail > temp;
    DisjointSet ds(n + 1);
    int counter = 0, sum = 0;
    for(multiset< Trail >::iterator it = mytrail.begin(); it != mytrail.end(); it++) {
        Trail currentTrail = *it;
        if(!ds.isSameSet(currentTrail.u, currentTrail.v)) {
            ds.unionSet(currentTrail.u, currentTrail.v);
            sum += currentTrail.l;
            counter++;
            temp.insert(currentTrail);
            if(counter == n - 1) break;
        }
    }
    if(counter == n - 1) ans[week] = sum;
    else ans[week] = -1;
    mytrail = temp;
}
