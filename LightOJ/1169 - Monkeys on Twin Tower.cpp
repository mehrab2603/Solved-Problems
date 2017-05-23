////////Recursuve////////

#include<bits/stdc++.h>

using namespace std;

const int MAX = 1100;

int n, eatTimeLeft[MAX], eatTimeRight[MAX], jumpTimeLeft[MAX], jumpTimeRight[MAX], dp[2][MAX];
bool vis[2][MAX];

int func(int, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &eatTimeLeft[i]);
        for(int i = 0; i < n; i++) scanf("%d", &eatTimeRight[i]);
        for(int i = 0; i < n - 1; i++) scanf("%d", &jumpTimeLeft[i]);
        for(int i = 0; i < n - 1; i++) scanf("%d", &jumpTimeRight[i]);
        memset(vis, false, sizeof vis);
        int ans = min(func(0, 0), func(1, 0));
        printf("Case %d: %d\n", ++caseno, ans);
    }
    return 0;
}

int func(int building, int floor) {
    if(floor == n - 1) {
        if(building) return eatTimeRight[floor];
        else return eatTimeLeft[floor];
    }
    if(vis[building][floor]) return dp[building][floor];
    int ret = INT_MAX;
    if(building) {
        ret = min(ret, eatTimeRight[floor] + func(1, floor + 1));
        ret = min(ret, eatTimeRight[floor] + jumpTimeRight[floor] + func(0, floor + 1));
    }
    else {
        ret = min(ret, eatTimeLeft[floor] + func(0, floor + 1));
        ret = min(ret, eatTimeLeft[floor] + jumpTimeLeft[floor] + func(1, floor + 1));
    }
    dp[building][floor] = ret;
    vis[building][floor] = true;
    return ret;
}

/*
////////iterative////////
#include<bits/stdc++.h>

using namespace std;

const int MAX = 1100;

int n, eatTimeLeft[MAX], eatTimeRight[MAX], jumpTimeLeft[MAX], jumpTimeRight[MAX], buildingLeft[MAX], buildingRight[MAX];

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &eatTimeLeft[i]);
        for(int i = 0; i < n; i++) scanf("%d", &eatTimeRight[i]);
        for(int i = 0; i < n - 1; i++) scanf("%d", &jumpTimeLeft[i]);
        for(int i = 0; i < n - 1; i++) scanf("%d", &jumpTimeRight[i]);
        buildingLeft[0] = eatTimeLeft[0];
        buildingRight[0] = eatTimeRight[0];
        for(int i = 1; i < n; i++) {
            buildingLeft[i] = eatTimeLeft[i] + min(buildingLeft[i - 1], buildingRight[i - 1] + jumpTimeRight[i - 1]);
            buildingRight[i] = eatTimeRight[i] + min(buildingRight[i - 1], buildingLeft[i - 1] + jumpTimeLeft[i - 1]);
        }
        printf("Case %d: %d\n", ++caseno, min(buildingLeft[n - 1], buildingRight[n - 1]));

    }
    return 0;
}
*/
