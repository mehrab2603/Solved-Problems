#include <bits/stdc++.h>

using namespace std;

struct Lines {
    int left, right;
    Lines(int left, int right) {this->left = left; this->right = right;}
};

class Compare {
    public:
    bool operator()(const Lines& l1, const Lines& l2) const {
        if(l1.left == l2.left) return l1.right > l2.right;
        return l1.left <  l2.left;
    }
};

vector< Lines > lines, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    bool start = false;
    while(t--) {
        if(start) printf("\n");
        else start = true;
        lines.clear();
        ans.clear();
        int m;
        scanf("%d", &m);
        int l, r;
        while(scanf("%d %d", &l, &r) && (l || r)) {
            lines.push_back(Lines(l, r));
        }
        sort(lines.begin(), lines.end(), Compare());
        int leftMark = 0, rightMark = 0, tempLeft = INT_MIN, tempRight = INT_MIN;
        bool flag = false;
        for(int i = 0; i < (int)lines.size(); i++) {
            if(lines[i].left <= leftMark && lines[i].right > rightMark) {
                rightMark = lines[i].right;
                tempLeft = lines[i].left;
                tempRight = lines[i].right;
            }
            else if(lines[i].left > leftMark && lines[i].left < m) {
                leftMark = rightMark;
                if(tempLeft != INT_MIN && tempRight != INT_MIN) ans.push_back(Lines(tempLeft, tempRight));
                else {tempLeft = INT_MIN, tempRight = INT_MIN; flag = true; break;}
                i--;
                tempLeft = INT_MIN, tempRight = INT_MIN;
                if(rightMark > m || leftMark > m) break;
            }
        }
        if(tempLeft != INT_MIN && tempRight != INT_MIN) ans.push_back(Lines(tempLeft, tempRight));
        if(flag) printf("0\n");
        else {
            printf("%d\n", (int)ans.size());
            sort(ans.begin(), ans.end(), Compare());
            for(int i = 0; i < (int)ans.size(); i++) printf("%d %d\n", ans[i].left, ans[i].right);
        }
    }
    return 0;
}
