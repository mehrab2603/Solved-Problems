#include <bits/stdc++.h>

using namespace std;

vector<int> adj[30];
set<int> inactive;
bool active[30];

int main() {
    int n, m;
    char initial[4];
    while(scanf("%d %d %s", &n, &m, initial) != EOF) {
        getchar();
        for(int i = 0; i < 30; i++)
            adj[i].clear();
        inactive.clear();
        memset(active, false, sizeof active);
        active[initial[0] - 'A'] = true;
        active[initial[1] - 'A'] = true;
        active[initial[2] - 'A'] = true;
        for(int i = 0; i < m; i++) {
            char a, b;
            scanf("%c%c", &a, &b);
            getchar();
            int aIndex = a - 'A', bIndex = b - 'A';
            bool aActive = active[aIndex], bActive = active[bIndex];
            adj[aIndex].push_back(bIndex);
            adj[bIndex].push_back(aIndex);
            if(!aActive) inactive.insert(aIndex);
            if(!bActive) inactive.insert(bIndex);
        }
        bool flag = false;
        int ans = 0, wakeCount = 0;
        while(!flag) {
            flag = true;
            vector<int> activated;
            for(set<int>::iterator it = inactive.begin(); it != inactive.end(); it++) {
                int u = *it;
                if(active[u]) continue;
                int counter = 0;
                for(int j = 0; j < (int)adj[u].size(); j++) {
                    int v = adj[u][j];
                    if(active[v])
                        counter++;
                }
                if(counter >= 3) {
                    flag = false;
                    activated.push_back(u);
                    inactive.erase(u);
                }
            }
            if(!flag) {
                ans++;
                wakeCount += activated.size();
                for(int i = 0; i < (int)activated.size(); i++) {
                    int u = activated[i];
                    active[u] = true;
                }
            }
        }
        if(wakeCount + 3 == n)
            printf("WAKE UP IN, %d, YEARS\n", ans);
        else
            printf("THIS BRAIN NEVER WAKES UP\n");

    }
    return 0;
}
