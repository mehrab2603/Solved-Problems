#include <bits/stdc++.h>

using namespace std;
int n, s, q;
vector< queue<int> > platform;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &s, &q);
        int total = 0;
        for(int i = 0; i < n; i++) {
            int qi;
            scanf("%d", &qi);
            total += qi;
            queue<int> q;
            for(int j = 0; j < qi; j++) {
                int x;
                scanf("%d", &x);
                q.push(x - 1);
            }
            platform.push_back(q);
        }
        stack<int> carrier;
        int current = 0, time = 0;
        while(total) {
            current = current % n;
            while(!carrier.empty()) {
                int top = carrier.top();
                if(top == current) total--;
                else if((int)platform[current].size() < q){
                    platform[current].push(top);
                }
                else if((int)platform[current].size() >= q)
                    break;
                carrier.pop();
                time++;
            }
            while((int)carrier.size() < s && !platform[current].empty()) {
                carrier.push(platform[current].front());
                platform[current].pop();
                time++;
            }
            if(total) time += 2;
            current++;
        }
        printf("%d\n", time);
        platform.clear();
    }
    return 0;
}
