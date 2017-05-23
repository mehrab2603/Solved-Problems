//max span tree solution

#include<bits/stdc++.h>

using namespace std;

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

map < string, int > mymap;

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int a, int b, int c) {u = a; v = b; w = c;}
    bool operator<(const Edge &e) const {return w > e.w;}
};

Edge edge[20000];
int adj[210][210], par[210];

int n, r, start, finish;

void kruskal();
void bfs();

int main() {
    int caseno = 0;
    while(scanf("%d %d", &n, &r) && (n || r)) {
        getchar();
        mymap.clear();
        int counter = 0;
        for(int i = 0; i < r; i++) {
            char city1[35], city2[35];
            int limit;
            scanf("%s %s %d", city1, city2, &limit);
            getchar();
            if(mymap.find(city1) == mymap.end()) {
                mymap[city1] = counter++;
            }
            if(mymap.find(city2) == mymap.end()) {
                mymap[city2] = counter++;
            }
            edge[i] = Edge(mymap[city1], mymap[city2], limit);
        }
        char st[35], ed[35];
        scanf("%s %s", st, ed);
        getchar();
        if(mymap.find(st) == mymap.end()) {
            printf("Scenario #%d\n%d tons\n\n", ++caseno, 0);
            continue;
        }
        if(mymap.find(ed) == mymap.end()) {
            printf("Scenario #%d\n%d tons\n\n", ++caseno, 0);
            continue;
        }
        start = mymap[st], finish = mymap[ed];
        kruskal();
        bfs();
        int dest = finish, ans = INT_MAX;
        while(par[dest] != -1) {
            ans = min(ans, adj[dest][par[dest]]);
            dest = par[dest];
        }
        printf("Scenario #%d\n%d tons\n\n", ++caseno, ans);
    }
    return 0;
}

void kruskal() {
    sort(edge, edge + r);
    memset(adj, 0, sizeof adj);
    DisjointSet ds(n);
    int counter = 0;
    for(int i = 0; i < r; i++) {
        Edge currentEdge = edge[i];
        if(!ds.isSameSet(currentEdge.u, currentEdge.v)) {
            ds.unionSet(currentEdge.u, currentEdge.v);
            adj[currentEdge.u][currentEdge.v] = currentEdge.w;
            adj[currentEdge.v][currentEdge.u] = currentEdge.w;
            counter++;
            if(counter == n - 1) break;
        }
    }
}

void bfs() {
    bool vis[210] = {false};
    par[start] = -1;
    queue < int > q;
    q.push(start);
    vis[start] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v = 0; v < n; v++) {
            if(adj[u][v] && u != v) {
                if(!vis[v]) {
                    vis[v] = true;
                    par[v] = u;
                    if(v == finish) return;
                    q.push(v);
                }
            }
        }
    }
    return;
}


/*

//floyd-warshall solution

#include<bits/stdc++.h>

using namespace std;

map < string, int > mymap;

int n, r, start, finish, adj[210][210];

void floydwarshall();

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int caseno = 0;
    while(scanf("%d %d", &n, &r) && (n || r)) {
        getchar();
        mymap.clear();
        int counter = 0;
        memset(adj, 0, sizeof adj);
        for(int i = 0; i < r; i++) {
            char city1[35], city2[35];
            int limit;
            scanf("%s %s %d", city1, city2, &limit);
            getchar();
            if(mymap.find(city1) == mymap.end()) {
                mymap[city1] = counter++;
            }
            if(mymap.find(city2) == mymap.end()) {
                mymap[city2] = counter++;
            }
            adj[mymap[city1]][mymap[city2]] = limit;
            adj[mymap[city2]][mymap[city1]] = limit;
        }
        char st[35], ed[35];
        scanf("%s %s", st, ed);
        getchar();
        if(mymap.find(st) == mymap.end()) {
            printf("Scenario #%d\n%d tons\n\n", ++caseno, 0);
            continue;
        }
        if(mymap.find(ed) == mymap.end()) {
            printf("Scenario #%d\n%d tons\n\n", ++caseno, 0);
            continue;
        }
        start = mymap[st], finish = mymap[ed];
        floydwarshall();
        printf("Scenario #%d\n%d tons\n\n", ++caseno, adj[start][finish]);
    }
    return 0;
}

void floydwarshall() {
    for(int i = 0; i < n; i++)
        adj[i][i] = 0;
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]));
}
*/
