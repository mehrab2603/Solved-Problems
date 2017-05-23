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

int main()
{
    int t, n, m;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        DisjointSet ds(n + 1);
        for(int i = 0; i < m; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            ds.unionSet(x, y);
        }
        int maxi = INT_MIN;
        for(int i = 1; i <= n; i++) {
            int s = ds.getSize(i);
            if(s > maxi) maxi = s;
        }
        printf("%d\n", maxi);
    }
    return 0;
}
