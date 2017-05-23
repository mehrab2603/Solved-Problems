#include<bits/stdc++.h>

using namespace std;

struct Number {
    char digit[15];
    int length;
    Number() {}
    Number(char* digit) {
        strcpy(this->digit, digit);
        this->length = strlen(this->digit);
    }
    bool operator<(const Number& n) const {return length < n.length;}
};

struct Node {
    bool endMark;
    Node* next[10];
    int counter;
    Node() {
        this->endMark = false;
        this->counter = 0;
        for(int i = 0; i < 10; i++)
            next[i] = NULL;
    }
}* root;

Number numbers[10010];

bool insertNumber(Number&);
void deleteNumber(Node*);

int main() {
    int t;
    scanf("%d%*c", &t);
    while(t--) {
        root = new Node();
        int n;
        scanf("%d", &n);
        getchar();
        char input[15];
        for(int i = 0; i < n; i++) {
            scanf("%s%*c", input);
            numbers[i] = Number(input);
        }
        sort(numbers, numbers + n);
        bool flag = false;
        for(int i = 0; i < n; i++) {
            if(!insertNumber(numbers[i])) {
                flag = true;
                break;
            }
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
        deleteNumber(root);
    }
    return 0;
}

bool insertNumber(Number& number) {
    Node* curr = root;
    for(int i = 0; i < number.length; i++) {
        int index = number.digit[i] - '0';
        if(curr->next[index] == NULL)
            curr->next[index] = new Node();
        curr = curr->next[index];
        if(curr->endMark && i < number.length - 1) return false;
    }
    curr->endMark = true;
    return true;
}

void deleteNumber(Node* curr) {
    for(int i = 0; i < 10; i++)
        if(curr->next[i] != NULL)
            deleteNumber(curr->next[i]);
    delete(curr);
}
