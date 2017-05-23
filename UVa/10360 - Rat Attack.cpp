#include<bits/stdc++.h>

using namespace std;

const int MAX = 1025;

int grid[MAX][MAX];


int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(grid, 0, sizeof grid);
        int d;
        scanf("%d", &d);
        int n;
        scanf("%d", &n);
        while(n--) {
            int x, y, p;
            scanf("%d %d %d", &x, &y, &p);
            for(int i = x - d; i <= x + d; i++)
                for(int j = y - d; j <= y + d; j++)
                    if(i >= 0 && i <= 1024 && j >= 0 && j <= 1024)
                        grid[i][j] += p;
        }
        int ansX, ansY, ansCount = INT_MIN;
        for(int i = 0; i < MAX; i++) {
            for(int j = 0; j < MAX; j++) {
                if(grid[i][j] > ansCount) {
                    ansCount = grid[i][j];
                    ansX = i;
                    ansY = j;
                }
                else if(grid[i][j] == ansCount) {
                    if(ansX == i) {
                        if(j < ansY) ansY = j;
                    }
                    else if(i < ansX) {
                        ansX = i;
                        ansY = j;
                    }
                }
            }
        }
        printf("%d %d %d\n", ansX, ansY, ansCount);
    }
    return 0;
}
