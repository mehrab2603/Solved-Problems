#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) && n)
    {
        int arr[n + 2];
        while(scanf("%d", &arr[0]) && arr[0])
        {
            for(int i = 1; i < n; i++)
                scanf("%d", &arr[i]);
            stack<int> station, dirA;
            dirA.push(-1);
            for(int i = n; i > 0; i--) dirA.push(i);
            int done = 0;
            station.push(-1);
            while(1)
            {
                if(dirA.top() == arr[done]) {dirA.pop(); done++;}
                else if(station.top() == arr[done]) {station.pop(); done++;}
                else
                {
                    if(dirA.top() == -1) break;
                    station.push(dirA.top());
                    dirA.pop();
                }
            }
            if(done >= n) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
