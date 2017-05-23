#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int a, int b, int c) {u = a; v = b; w = c;}
};

vector< Edge > edge;
int dist[110];

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        edge.clear();
        int n, r, p;
        scanf("%d %d %d", &n, &r, &p);
        for(int j = 0; j < r; j++) {
            int a, b, i, e;
            scanf("%d %d %d %d", &a, &b, &i, &e);
            edge.push_back(Edge(a, b, p * e - i));
        }
        memset(dist, 63, sizeof dist);
        dist[0] = 0;
        bool negativeFlag = false;
        for(int i = 0; i < n; i++) {
            bool updateFlag = false;
            for(int j = 0; j < r; j++) {
                int u = edge[j].u, v = edge[j].v, w = edge[j].w;
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updateFlag = true;
                    if(i + 1 == n)
                        negativeFlag = true;
                }
            }
            if(!updateFlag) break;
        }
        if(negativeFlag)
            printf("Case %d: YES\n", ++caseno);
        else
            printf("Case %d: NO\n", ++caseno);

    }
    return 0;
}
