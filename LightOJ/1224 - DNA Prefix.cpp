#include<bits/stdc++.h>

using namespace std;

struct Node {
    Node *next[4];
    int depth, visited;
    Node(int a) {
        depth = a;
        visited = 0;
        next[0] = NULL;
        next[1] = NULL;
        next[2] = NULL;
        next[3] = NULL;
    }
} *root;

void trieInsert(char [], int);
int trieTraverse(Node *);
void trieDelete(Node *);
int getValue(char);

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        root = new Node(0);
        int n;
        scanf("%d", &n);
        getchar();
        char input[55];
        while(n--) {
            scanf("%s", input);
            getchar();
            trieInsert(input, strlen(input));
        }
        printf("Case %d: %d\n", ++caseno, trieTraverse(root));
        trieDelete(root);
    }
    return 0;
}

void trieInsert(char s1[], int length) {
    Node *current = root;
    for(int i = 0; i < length; i++) {
        current->visited++;
        int value = getValue(s1[i]);
        if(current->next[value] == NULL)
            current->next[value] = new Node(current->depth + 1);
        current = current->next[value];
    }
    current->visited++;
}

int trieTraverse(Node *current) {
    int ans = current->depth * current->visited;
    for(int i = 0; i < 4; i++)
        if(current->next[i])
            ans = max(ans, trieTraverse(current->next[i]));
    return ans;
}

void trieDelete(Node *current) {
    for(int i = 0; i < 4; i++)
        if(current->next[i])
            trieDelete(current->next[i]);
    delete current;
}

int getValue(char ch) {
    if(ch == 'A') return 0;
    else if(ch == 'C') return 1;
    else if(ch == 'G') return 2;
    else return 3;
}
