#include <bits/stdc++.h>

using namespace std;

bool flag[50010];

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

int main()
{
    int n, m, caseno = 0;
    while(scanf("%d %d", &n, &m) && (n || m)) {
        memset(flag, false, sizeof flag);
        DisjointSet ds(n + 1);
        for(int i = 0; i < m; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            ds.unionSet(x, y);
        }
        int counter = 0;
        for(int i = 1; i <= n; i++) {
            int setNum = ds.findSet(i);
            if(!flag[setNum]) {
                flag[setNum] = true;
                counter++;
            }
        }
        printf("Case %d: %d\n", ++caseno, counter);
    }
    return 0;
}
