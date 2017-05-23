#include <bits/stdc++.h>

using namespace std;
stack<char> stSource, stDest;
string source, dest;
int len;
void func(int, string);

int main() {
    while(cin >> source >> dest) {
        for(int i = dest.length() - 1; i >= 0; i--)
            stDest.push(dest[i]);
        len = source.length();
        printf("[\n");
        if(source.length() == dest.length())
            func(0, "");
        printf("]\n");
        while(!stDest.empty())
            stDest.pop();
        while(!stSource.empty())
            stSource.pop();
    }
    return 0;
}


void func(int index, string seq) {
    if(index == len && (int)seq.length() == 2 * len) {
        printf("%c", seq.c_str()[0]);
        for(int i = 1; i < 2 * len; i++) {
            printf(" %c", seq.c_str()[i]);
        }
        printf("\n");
        return;
    }
    if(index < len) {
        stSource.push(source[index]);
        func(index + 1, seq + "i");
        stSource.pop();
    }
    if(!stSource.empty() && stDest.top() == stSource.top()) {
        char ch1 = stDest.top();
        char ch2 = stSource.top();
        stDest.pop();
        stSource.pop();
        func(index, seq + "o");
        stDest.push(ch1);
        stSource.push(ch2);
    }
}
