#include <bits/stdc++.h>

using namespace std;
struct compare{
    bool operator()(int a, int b) {return a > b;}
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    bool flag = false;
    while(n--) {
        if(flag) printf("\n");
        else flag = true;
        int b, sg, sb;
        scanf("%d %d %d", &b, &sg, &sb);
        multiset<int, compare> blue, green, temp;
        for(int i = 0; i < sg; i++) {
            int power;
            scanf("%d", &power);
            green.insert(power);
        }
        for(int i = 0; i < sb; i++) {
            int power;
            scanf("%d", &power);
            blue.insert(power);
        }
        while(!green.empty() && !blue.empty()) {
            vector<int> greenSurvivor, blueSurvivor;
            for(int i = 0; i < b && !green.empty() && !blue.empty(); i++) {
                int greenLemming, blueLemming;
                greenLemming = *green.begin();
                blueLemming = *blue.begin();
                green.erase(green.begin());
                blue.erase(blue.begin());
                if(greenLemming > blueLemming)
                    greenSurvivor.push_back(greenLemming - blueLemming);
                else if(blueLemming > greenLemming)
                    blueSurvivor.push_back(blueLemming - greenLemming);
            }
            for(int i = 0; i < (int)greenSurvivor.size(); i++)
                green.insert(greenSurvivor[i]);
            for(int i = 0; i < (int)blueSurvivor.size(); i++)
                blue.insert(blueSurvivor[i]);
        }
        if(green.empty() && blue.empty())
            printf("green and blue died\n");
        else if(green.empty()) {
            printf("blue wins\n");
            for(set<int>::iterator it = blue.begin(); it != blue.end(); it++)
                printf("%d\n", *it);
        }
        else {
            printf("green wins\n");
            for(set<int>::iterator it = green.begin(); it != green.end(); it++)
                printf("%d\n", *it);
        }
    }
    return 0;
}
