#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    bool start = false;
    while(scanf("%d", &n) && n) {
        if(!start) start = true;
        else printf("\n");
        bool ans = false;
        for(int denominator = 1234; denominator <= 98765 / n; denominator++) {
            int numerator = denominator * n;
            int flag = 0;
            if(denominator < 10000)  flag |= 1;
            int temp = numerator;
            while(temp) {flag |= (1 << (temp % 10)); temp /= 10;}
            temp = denominator;
            while(temp) {flag |= (1 << (temp % 10)); temp /= 10;}
            if(flag == (1 << 10) - 1) {
                ans = true;
                if(denominator < 10000) printf("%d / 0%d = %d\n", numerator, denominator, n);
                else printf("%d / %d = %d\n", numerator, denominator, n);
            }
        }
        if(!ans) printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
