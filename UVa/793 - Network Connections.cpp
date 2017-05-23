#include <bits/stdc++.h>

using namespace std;

class UnionFindDisjointSet {
private:
    vector<int> par, ran;
public:
    UnionFindDisjointSet(int n) {
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

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    bool flag = false;
    while(t--) {
        if(flag) printf("\n");
        else flag = true;
        int n;
        scanf("%d", &n);
        getchar();
        UnionFindDisjointSet ds(n + 1);
        int successful = 0, unsuccessful = 0;
        char ch;
        int comp1, comp2;
        while(scanf("%c", &ch) != EOF && ch != '\n') {
            scanf("%d %d", &comp1, &comp2);
            getchar();
            if(ch == 'c') {
                ds.unionSet(comp1, comp2);
            }
            else {
                if(ds.isSameSet(comp1, comp2))
                    successful++;
                else
                    unsuccessful++;

            }
        }
        printf("%d,%d\n", successful, unsuccessful);
    }
    return 0;
}
