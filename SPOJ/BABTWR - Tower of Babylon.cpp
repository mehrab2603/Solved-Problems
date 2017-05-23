#include <bits/stdc++.h>

using namespace std;

const int MAX = 30 * 6 + 5;

struct Block {
    int x, y, z;
    Block() {}
    Block(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    bool operator<(const Block& b) const {
        if(this->x == b.x) {
            if(this->y == b.y)
                return this->z < b.z;
            return this->y < b.y;
        }
        return this->x < b.x;
    }
};

set< Block > blocks;
Block arr[MAX];
int dp[MAX], last;
bool vis[MAX];

int func(int);

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) && n) {
        blocks.clear();
        for(int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            blocks.insert(Block(x, y, z));
            blocks.insert(Block(y, x, z));
            blocks.insert(Block(x, z, y));
            blocks.insert(Block(z, x, y));
            blocks.insert(Block(y, z, x));
            blocks.insert(Block(z, y, x));
        }
        last = 0;
        for(set< Block >::iterator it = blocks.begin(); it != blocks.end(); it++)
            arr[last++] = *it;
        memset(vis, false, sizeof vis);
        int ans = 0;
        for(int i = 0; i < last; i++)
            ans = max(ans, func(i));
        printf("%d\n", ans);
    }
    return 0;
}

int func(int index) {
    if(vis[index]) return dp[index];
    int ret = arr[index].z;
    for(int i = index + 1; i < last; i++) {
        if(arr[i].x > arr[index].x && arr[i].y > arr[index].y)
            ret = max(ret, arr[index].z + func(i));
    }
    vis[index] = true;
    return dp[index] = ret;
}
