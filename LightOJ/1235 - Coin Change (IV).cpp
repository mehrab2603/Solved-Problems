#include<bits/stdc++.h>

using namespace std;

map< int, bool > mymap;

int arr[20];
bool flag;

void func(int, int, int, int, int);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        mymap.clear();
        int n, k, mid;
        scanf("%d %d", &n, &k);
        mid = (n / 2);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        flag = false;
        if(!flag) func(0, 0, mid, k, 0);
        if(!flag) func(mid, 0, n, k, 1);
        printf("Case %d: ", ++caseno);
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

void func(int index, int sum, int last, int make, int mode) {
    if(index == last) {
        mymap[sum] = true;
        if(mode == 1 && mymap[make - sum]) flag = true;
        if(mymap[make]) flag = true;
        return;
    }
    if(!flag) func(index + 1, sum, last, make, mode);
    if(!flag && sum + arr[index] <= make) func(index + 1, sum + arr[index], last, make, mode);
    if(!flag && sum + 2 * arr[index] <= make) func(index + 1, sum + 2 * arr[index], last, make, mode);
}
