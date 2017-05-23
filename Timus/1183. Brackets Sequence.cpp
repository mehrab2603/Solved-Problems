#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

char input[MAX];

int dp[MAX][MAX], trace[MAX][MAX];

int f(int i, int j) {
    if(i > j) {
        trace[i][j] = 7;
        return 0;
    }
    if(i == j) {
        if(input[i] == '(' || input[i] == ')') trace[i][j] = 8;
        else if(input[i] == '[' || input[i] == ']') trace[i][j] = 9;
        return 1;
    }
    if(dp[i][j] != -1) return dp[i][j];
    int &ret = dp[i][j];
    ret = INT_MAX;
    if(input[i] == '(' && input[j] == ')') {
        ret = f(i + 1, j - 1);
        trace[i][j] = 1;
    }
    else if(input[i] == '[' && input[j] == ']') {
        ret = f(i + 1, j - 1);
        trace[i][j] = 2;
    }
    else if(input[i] == '(' && input[j] != ')') {
        ret = 1 + f(i + 1, j);
        trace[i][j] = 3;
    }
    else if(input[i] != '(' && input[j] == ')') {
        ret = 1 + f(i, j - 1);
        trace[i][j] = 4;
    }
    else if(input[i] == '[' && input[j] != ']') {
        ret = 1 + f(i + 1, j);
        trace[i][j] = 5;
    }
    else if(input[i] != '[' && input[j] == ']') {
        ret = 1 + f(i, j - 1);
        trace[i][j] = 6;
    }
    for(int k = i; k < j; k++) {
        int temp = f(i, k) + f(k + 1, j);
        if(temp < ret) {
            ret = temp;
            trace[i][j] = 20 + k;
        }
    }
    return ret;
}

void print(int i, int j) {
    if(trace[i][j] == 1) {
        printf("(");
        print(i + 1, j - 1);
        printf(")");
    }
    else if(trace[i][j] == 2) {
        printf("[");
        print(i + 1, j - 1);
        printf("]");
    }
    else if(trace[i][j] == 3) {
        printf("(");
        print(i + 1, j);
        printf(")");
    }
    else if(trace[i][j] == 4) {
        printf("(");
        print(i, j - 1);
        printf(")");
    }
    else if(trace[i][j] == 5) {
        printf("[");
        print(i + 1, j);
        printf("]");
    }
    else if(trace[i][j] == 6) {
        printf("[");
        print(i, j - 1);
        printf("]");
    }
    else if(trace[i][j] == 7) {
        return;
    }
    else if(trace[i][j] == 8) {
        printf("()");
        return;
    }
    else if(trace[i][j] == 9) {
        printf("[]");
        return;
    }
    else if(trace[i][j] >= 20) {
        int k = trace[i][j] - 20;
        print(i, k);
        print(k + 1, j);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%s", input);
    memset(dp, -1, sizeof dp);
    f(0, strlen(input) - 1);
    print(0, strlen(input) - 1);
    printf("\n");
    return 0;
}
