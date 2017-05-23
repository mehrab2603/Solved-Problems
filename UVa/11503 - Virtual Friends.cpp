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

map<string, int> people;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int f;
        scanf("%d", &f);
        getchar();
        int counter = 0;
        DisjointSet ds(2 * f);
        people.clear();
        for(int i = 0; i < f; i++) {
            char person1[25], person2[25];
            scanf("%s %s", person1, person2);
            getchar();
            if(people.find(person1) == people.end()) {
                people[person1] = counter++;
            }
            if(people.find(person2) == people.end()) {
                people[person2] = counter++;
            }
            ds.unionSet(people[person1], people[person2]);
            printf("%d\n", ds.getSize(people[person1]));
        }
    }
    return 0;
}
