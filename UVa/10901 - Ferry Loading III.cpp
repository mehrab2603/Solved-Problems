#include <bits/stdc++.h>

using namespace std;

struct Car {
    int number, time;
    Car() {}
    Car(int a, int b) {number = a, time = b;}
};

int ans[10010];

int main() {
    int c;
    scanf("%d", &c);
    getchar();
    bool flag = false;
    while(c--) {
        if(flag) printf("\n");
        else flag = true;
        queue<Car> qLeft, qRight;
        int n, t, m;
        scanf("%d %d %d", &n, &t, &m);
        getchar();
        for(int i = 0; i < m; i++) {
            char s[10];
            int time;
            scanf("%d %s", &time, s);
            getchar();
            Car car(i, time);
            if(s[0] == 'r')
                qRight.push(car);
            else
                qLeft.push(car);
        }
        int time = 0, direction = 0, loaded = 0;
        while(!qLeft.empty() || !qRight.empty()) {
            if(direction == 0) {
                while(!qLeft.empty() && loaded < n) {
                    int currNumber = qLeft.front().number;
                    int currTime = qLeft.front().time;
                    if(currTime <= time) {
                        loaded++;
                        qLeft.pop();
                        ans[currNumber] = time + t;
                    }
                    else break;
                }
            }
            else {
                while(!qRight.empty() && loaded < n) {
                    int currNumber = qRight.front().number;
                    int currTime = qRight.front().time;
                    if(currTime <= time) {
                        loaded++;
                        qRight.pop();
                        ans[currNumber] = time + t;
                    }
                    else break;
                }


            }
            if(loaded || (!qLeft.empty() && qLeft.front().time <= time) || (!qRight.empty() && qRight.front().time <= time)) {
                loaded = 0;
                time += t;
                direction = (direction + 1) % 2;
            }
            else
                time++;
        }
        for(int i = 0; i < m; i++) printf("%d\n", ans[i]);
    }
    return 0;
}
