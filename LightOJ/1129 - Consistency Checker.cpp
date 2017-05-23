#include<bits/stdc++.h>

using namespace std;

struct Node {
    bool endFlag;
    Node *next[10];
    Node() {
        endFlag = false;
        for(int i = 0; i < 10; i++)
            next[i] = NULL;
    }
} *root;

bool trieInsert(char [], int);
void trieDelete(Node *);

int main() {
    //freopen("input.txt", "r", stdin);
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        root = new Node();
        int n;
        scanf("%d", &n);
        getchar();
        char input[15];
        bool flag = false;
        for(int i = 0; i < n; i++) {
            scanf("%s", input);
            getchar();
            if(!flag) flag = trieInsert(input, strlen(input));
        }
        printf("Case %d: ", ++caseno);
        if(flag) printf("NO\n");
        else printf("YES\n");
        trieDelete(root);
    }
    return 0;
}

bool trieInsert(char s1[], int length) {
    Node *current = root;
    int insertCount = 0;
    bool hasEnd = false;
    for(int i = 0; i < length; i++) {
        if(current->endFlag) hasEnd = true;
        int value = s1[i] - '0';
        if(current->next[value] == NULL) {
            current->next[value] = new Node();
            insertCount++;
        }
        current = current->next[value];
    }
    current->endFlag = true;
    if(hasEnd || !insertCount) return true;
    else return false;
}
void trieDelete(Node *current) {
    for(int i = 0; i < 10; i++) {
        if(current->next[i])
            trieDelete(current->next[i]);
    }
    delete current;
}
