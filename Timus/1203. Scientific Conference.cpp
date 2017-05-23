#include <bits/stdc++.h>

using namespace std;

struct Section {
    int s, e;
    Section() {}
    Section(int s, int e) {
        this->s = s;
        this->e = e;
    }
    bool operator<(const Section& sec) const {
        if(this->e == sec.e) return this->s > sec.s;
        return this->e < sec.e;
    }
};

Section sections[100001];



int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d %d", &sections[i].s, &sections[i].e);

    sort(sections, sections + n);

    int ans = 0, last = -1;

    for(int i = 0; i < n; i++) {
        if(sections[i].s > last) {
            ans++;
            last = sections[i].e;
        }
    }
    printf("%d\n", ans);

    return 0;
}
