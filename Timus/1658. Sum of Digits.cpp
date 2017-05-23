#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000000;

int dp[901][8101];
char track[901][8101];

int f(int s, int d) {
    if(s == 0 && d == 0)  {track[s][d] = '\0'; return 0;}
    if(s == 0 && d != 0) return MAX;
    if(s != 0 && d == 0) return MAX;
    if(s < 0 || d < 0) return MAX;

    int &ret = dp[s][d];

    if(ret != 0) return ret;

    ret = MAX;
    for(int i = 0; i < 10; i++) {
        int temp = 1 + f(s - i, d - i * i);
        if(temp < ret) {
            ret = temp;
            track[s][d] = '0' + i;
        }
    }
    return ret;
}

void print(int s, int d) {
    if(track[s][d] != '\0') {
        int digit = track[s][d] - '0';
        printf("%d", digit);
        print(s - digit, d - digit * digit);
    }
    else printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int s1, s2;
        scanf("%d %d", &s1, &s2);
        if(s1 > 900 || s2 > 8100) {
            printf("No solution\n");
            continue;
        }

        int ret = MAX, firstDigit = -1;
        for(int i = 1; i < 10; i++) {
            int temp = 1 + f(s1 - i, s2 - i * i);
            if(temp < ret) {
                firstDigit = i;
                ret = temp;
            }
        }
        if(ret > 100) {
            printf("No solution\n");
            continue;
        }
        else {
            printf("%d", firstDigit);
            print(s1 - firstDigit, s2 - firstDigit * firstDigit);
        }
    }
    return 0;
}
