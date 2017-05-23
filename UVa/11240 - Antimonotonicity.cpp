#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        bool small = false;
        int counter = 0;
        int fred, lastFred = INT_MIN;
        for(int i = 0; i < n; i++) {
            scanf("%d", &fred);
            if(!small) {
                if(fred < lastFred) {
                    lastFred = fred;
                }
                else if(fred > lastFred) {
                    counter++;
                    lastFred = fred;
                    small = !small;
                }
            }
            else {
                if(fred > lastFred) {
                    lastFred = fred;
                }
                else if(fred < lastFred){
                    if(fred < lastFred) {
                        counter++;
                        lastFred = fred;
                        small = !small;
                    }
                }
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}
