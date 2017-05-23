#include<bits/stdc++.h>

using namespace std;

int word[1010];

int main() {
    int n, l, c;
    while(scanf("%d %d %d", &n, &l, &c) != EOF) {
        getchar();
        char input[75];
        for(int i = 0; i < n; i++) {scanf("%s", input); word[i] = strlen(input);}
        int lastChar = word[0], lastLine = 1;
        for(int i = 1; i < n; i++) {
            if(lastChar + 1 + word[i] <= c) lastChar = lastChar + 1 + word[i];
            else {
                lastLine++;
                lastChar = word[i];
            }
        }
        printf("%d\n", (int)ceil((lastLine * 1.0) / l));
    }
    return 0;
}
