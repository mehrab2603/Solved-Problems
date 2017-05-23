#include <bits/stdc++.h>

using namespace std;

struct Compare {
    bool operator()(int a, int b) {
        if(a >= b) return true;
        return false;
    }
};

priority_queue<int, vector<int>, Compare> q;
//priority_queue<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) && n) {

        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            q.push(x);
        }
        int ans = 0;
        while(q.size() != 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            ans += a + b;
            q.push(a + b);
        }
        printf("%d\n", ans);
        q.pop();
    }
    return 0;
}
