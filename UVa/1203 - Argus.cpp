#include <bits/stdc++.h>

using namespace std;
struct Query {
    int id, period, next;
    Query() {}
    Query (int a, int b, int c) {id = a; period = b; next = c;}
};

struct Compare {
    bool operator()(Query q1, Query q2) {
        if(q1.next > q2.next)
            return true;
        else if(q1.next == q2.next)
            return q1.id > q2.id;
        else
            return false;
    }
};
priority_queue<Query, vector<Query>, Compare> q;

int main() {
    char command[10];
    while(scanf("%s", command) && strcmp(command, "#") != 0) {
        int id, period;
        scanf("%d %d", &id, &period);
        getchar();
        q.push(Query(id, period, period));
    }
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        Query query = q.top();
        q.pop();
        q.push(Query(query.id, query.period, query.next + query.period));
        printf("%d\n", query.id);
    }
    return 0;
}
