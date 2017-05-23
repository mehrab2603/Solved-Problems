#include<bits/stdc++.h>

using namespace std;

int stepRequired(int, int);

int main() {
    int a, u, v;
    while(scanf("%d %d %d%*c", &a, &u, &v) != EOF) {
        if(a == 0) printf("0\n");
        else printf("%d\n", max(stepRequired(a, u), stepRequired(0, v)));
    }
    return 0;
}

int stepRequired(int thiefPosition, int thiefSpeed) {
    for(int i = 1;; i++) {
        if((i * (i + 1)) / 2 >= thiefPosition + i * thiefSpeed) return i;
    }
    return -1;
}
