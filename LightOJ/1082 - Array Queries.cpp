#include <bits/stdc++.h>

using namespace std;
int arr[100010];
int tree[3 * 100010];
void init(int, int, int);
int query(int, int, int, int, int);

int main()
{
    //freopen("output.txt", "r", stdout);
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        init(1, 1, n);
        printf("Case %d:\n", ++caseno);
        for(int k = 0; k < q; k++)
        {
            int i, j;
            scanf("%d %d", &i, &j);
            printf("%d\n", query(1, 1, n, i, j));
        }

    }
    return 0;
}

void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (b + e) / 2;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b) return INT_MAX;
    if(b >= i && e <= j) return tree[node];
    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (b + e) / 2;
    int lq = query(left, b, mid, i, j);
    int rq = query(right, mid + 1, e, i, j);
    return min(lq, rq);
}
