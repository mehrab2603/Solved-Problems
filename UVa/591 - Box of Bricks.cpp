#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int caseno = 0;
    while(1)
    {
        int n, arr[60], sum = 0;
        scanf("%d", &n);
        if(n == 0) break;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            sum = sum + arr[i];
        }
        int height = sum / n;
        int ans = 0;
        for(int j = 0; j < n; j++)
            if(arr[j] > height)
                ans = ans + (arr[j] - height);
        printf("Set #%d\n", ++caseno);
        printf("The minimum number of moves is %d.\n", ans);
        puts("");
    }

    return 0;
}
