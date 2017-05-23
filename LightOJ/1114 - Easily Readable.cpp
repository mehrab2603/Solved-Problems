#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;

int nextNode[MAX][52], counter[MAX], nextFreeNode;
char line[10001], *lineWord;

int getKey(char);
void insertWord(char *, int);
int searchWord(char *, int);


int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        memset(nextNode, -1, sizeof nextNode);
        memset(counter, 0, sizeof counter);
        nextFreeNode = 1;
        int n;
        scanf("%d", &n);
        getchar();
        while(n--) {
            char word[101];
            scanf("%s", word);
            getchar();
            int length = strlen(word);
            if(length > 3)sort(word + 1, word + length - 1);
            insertWord(word, length);
        }
        int m;
        scanf("%d", &m);
        getchar();

        printf("Case %d:\n", ++caseno);
        while(m--) {
            int ans = 1;
            gets(line);
            lineWord = strtok(line, " ");
            while(lineWord != NULL && ans) {
                int length = strlen(lineWord);
                if(length > 3) sort(lineWord + 1, lineWord + length - 1);
                ans *= searchWord(lineWord, length);
                lineWord = strtok(NULL, " ");
            }
            printf("%d\n", ans);
        }

    }
    return 0;
}

void insertWord(char *word, int length) {
    int current = 0;
    for(int i = 0; i < length; i++) {
        int key = getKey(word[i]);
        if(nextNode[current][key] == -1) current = nextNode[current][key] = nextFreeNode++;
        else current = nextNode[current][key];
    }
    counter[current]++;
}

int searchWord(char *word, int length) {
    int current = 0;
    for(int i = 0; i < length; i++) {
        int key = getKey(word[i]);
        if(nextNode[current][key] == -1) return 0;
        else current = nextNode[current][key];
    }
    return counter[current];
}

int getKey(char c) {
    if(c >= 'a' && c <= 'z') return c - 'a';
    else return c - 'A' + 26;
}
