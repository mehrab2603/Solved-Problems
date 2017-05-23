#include <bits/stdc++.h>

using namespace std;
map <set <int>, int> frosh;

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        frosh.clear();
        int ans = 0, temp = 0;
        for(int i = 0; i < n; i++) {
            set <int> courses;
            for(int i = 0; i < 5; i++) {
                int x;
                scanf("%d", &x);
                courses.insert(x);
            }
            frosh[courses]++;
            temp = max(temp, frosh[courses]);
        }
        map <set <int>, int>::iterator it;
        for(it = frosh.begin(); it != frosh.end(); it++)
            if(it->second == temp)
                ans += it->second;
        printf("%d\n", ans);
    }
    return 0;
}
