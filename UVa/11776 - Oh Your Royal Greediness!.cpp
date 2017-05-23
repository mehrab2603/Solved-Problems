#include<bits/stdc++.h>

using namespace std;

struct Point {
    int value;
    bool startFlag;
    Point() {}
    Point(int value, bool startFlag) {this->value = value; this->startFlag = startFlag;}
    bool operator<(const Point& p) const {return value == p.value ? startFlag > p.startFlag : value < p.value;}
};

Point points[2 * 1001];

int main() {
    int n, caseno = 0;
    while(scanf("%d", &n) && n != -1) {
        for(int i = 0; i < n; i++) {
            int start, finish;
            scanf("%d %d", &start, &finish);
            points[2 * i] = Point(start, true);
            points[2 * i + 1] = Point(finish, false);
        }
        sort(points, points + 2 * n);
        int active = 0, ans = 0;
        for(int i = 0; i < 2 * n; i++) {
            if(points[i].startFlag) active++;
            else active--;
            ans = max(ans, active);
        }
        printf("Case %d: %d\n", ++caseno , ans);
    }
    return 0;
}
