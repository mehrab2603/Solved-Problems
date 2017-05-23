#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int caseno = 0;
    while(cin >> s && s != "end") {
        char q[1001] = {'Z' + 1};
        int counter1 = 1;
        for(int i = 0; i < (int)s.length(); i++) {
            for(int j = 0; j < counter1; j++) {
                if(s[i] <= q[j]) {
                    q[j] = s[i];
                    break;
                }
                else if(j == counter1 - 1) {
                    q[j + 1] = s[i];
                    counter1++;
                    break;
                }
            }
        }
        bool vis[26] = {false};
        int counter2 = 0;
        for(int i = 0; i < (int)s.length(); i++) {
            if(!vis[s[i] - 'A']) {
                counter2++;
                vis[s[i] - 'A'] = true;
            }
        }
        printf("Case %d: %d\n", ++caseno, min(counter1, counter2));
    }
    return 0;
}
