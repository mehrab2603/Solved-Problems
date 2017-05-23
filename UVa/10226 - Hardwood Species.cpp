#include <bits/stdc++.h>

using namespace std;

int amount[10010];
map <string, int> species;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    getchar();
    getchar();
    bool flag = false;
    while(t--) {
        if(flag) printf("\n");
        else flag = true;
        char tree[50];
        int counter = 0;
        int total = 0;
        species.clear();
        memset(amount, 0, sizeof amount);
        while(gets(tree) && strcmp(tree, "") != 0) {
            if(species.find(tree) == species.end()) {
                species[tree] = counter++;
            }
            int treeNumber = species[tree];
            amount[treeNumber]++;
            total++;
        }
        map <string, int>::iterator it;
        for(it = species.begin(); it != species.end(); it++) {
            printf("%s %.4lf\n", it->first.c_str(), (amount[it->second] / (double)total) * 100);
        }
    }
    return 0;
}
