#include<bits/stdc++.h>

using namespace std;

const int MAX = 30005, LOG = log2(MAX);

int values[MAX];

//LCA
int L[MAX], T[MAX], P[MAX][LOG + 1], subsize[MAX], maxsubindex[MAX];
vector< int > adj[MAX];

void dfs(int from, int u, int dep) {
    T[u] = from;
    L[u] = dep;
    subsize[u] = 1;
    maxsubindex[u] = -1;
    int maxi = -1;
    for(int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == from) continue;
        dfs(u, v, dep + 1);
        subsize[u] += subsize[v];
        if(subsize[v] > maxi) {
            maxi = subsize[v];
            maxsubindex[u] = i;
        }
    }
}

int lcaQuery(int n, int p, int q) {
    if(L[p] < L[q]) swap(p, q);

    int log = 1;

    while(1) {
        if((1 << (log + 1)) > L[p]) break;
        log++;
    }
    for(int i = log; i >= 0; i--)
        if(L[p] - (1 << i) >= L[q])
            p = P[p][i];
    if(p == q) return p;
    for(int i = log; i >= 0; i--)
        if(P[p][i] != -1 && P[p][i] != P[q][i])
            p= P[p][i], q = P[q][i];
    return T[p];
}

void lcaInit(int n) {
    dfs(0, 0, 0);
    memset(P, -1, sizeof P);
    for(int i = 0; i < n; i++)
        P[i][0] = T[i];
    for(int j = 1; 1 << j < n; j++)
        for(int i = 0; i < n; i++)
            if(P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

//HLD
int chainNo, chainHead[MAX], chainSize[MAX], chainInd[MAX], chainPos[MAX], baseNo, baseInd[MAX], baseArray[MAX];

void hld(int from, int u, int val) {
    if(chainHead[chainNo] == -1) chainHead[chainNo] = u;
    chainInd[u] = chainNo;
    chainPos[u] = chainSize[chainNo];
    chainSize[chainNo]++;

    baseInd[u] = baseNo;
    baseArray[baseNo++] = val;

    int ind = maxsubindex[u];
    if(ind >= 0 && adj[u][ind] != from) hld(u, adj[u][ind], values[ adj[u][ind] ]);

    for(int i = 0; i < (int)adj[u].size(); i++) {
        if(i != ind && adj[u][i] != from) {
            chainNo++;
            hld(u, adj[u][i], values[ adj[u][i] ]);
        }
    }
}

void hldInit(int n, int root) {
    chainNo = 0;
    baseNo = 0;
    for(int i = 0; i < n; i++) {
        chainHead[i] = -1;
        chainSize[i] = 0;
    }
    hld(root, root, values[root]);
}

//Segment tree

int tree[4 * MAX];

void treeInit(int node, int b, int e) {
    if(b == e) {
        tree[node] = baseArray[b];
        return;
    }
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    treeInit(left, b, mid);
    treeInit(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
    return;
}

void treeUpdate(int node, int b, int e, int target, int val) {
    if(e < target || b > target) return;
    if(b >= target && e <= target) {
        tree[node] = val;
        return;
    }
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    treeUpdate(left, b, mid, target, val);
    treeUpdate(right, mid + 1, e, target, val);
    tree[node] = tree[left] + tree[right];
    return;
}

int treeQuery(int node, int b, int e, int i, int j) {
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[node];
    int left = 2 * node, right = left + 1, mid = (b + e) / 2;
    return treeQuery(left, b, mid, i, j) + treeQuery(right, mid + 1, e, i, j);
}

int query(int n, int u, int v) {

    if(u == v) return treeQuery(1, 0, n - 1, baseInd[u], baseInd[u]);
    int uchain, vchain = chainInd[v], ans = 0;

    while(1) {
		uchain = chainInd[u];
		if(uchain == vchain) {
			ans += treeQuery(1, 0, n - 1, baseInd[v], baseInd[u]);
            break;
		}
		ans += treeQuery(1, 0, n - 1, baseInd[chainHead[uchain]], baseInd[u]);
		u = chainHead[uchain];
		u = P[u][0];
	}
	return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) adj[i].clear();
        for(int i = 0; i < n; i++) scanf("%d", &values[i]);
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        lcaInit(n);
        hldInit(n, 0);
        treeInit(1, 0, n - 1);
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", ++caseno);

        while(q--) {
            int command;
            scanf("%d", &command);
            if(command) {
                int i, v;
                scanf("%d %d", &i, &v);
                treeUpdate(1, 0, n - 1, baseInd[i], v);
            }
            else {
                int i, j;
                scanf("%d %d", &i, &j);
                int lca = lcaQuery(n, i, j);
                printf("%d\n", query(n, i, lca) + query(n, j, lca) - query(n, lca, lca));
            }
        }
    }
    return 0;
}
