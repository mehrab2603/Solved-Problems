#include<bits/stdc++.h>

using namespace std;

bool setFlag[33];
unsigned int arr[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648};

int main() {
    unsigned int n, l, u;
    while(scanf("%u %u %u%*c", &n, &l, &u) != EOF) {
        unsigned int ans = 0, index = 1;
        for(int i = 0; i < 32; i++) {
            if(n & index) setFlag[i] = true;
            else setFlag[i] = false;
            index <<= 1;
        }
        index = 2147483648;
        for(int i = 31; i >= 0; i--) {
            if(setFlag[i]) {
                if(ans < l && arr[i] <= l - ans) {
                    ans = ans | index;
                }
            }
            else {
                long long temp = ans | index;
                if(temp <= u) ans = temp;
            }
            index >>= 1;
        }
        printf("%u\n", ans);
    }
    return 0;
}
