#include <bits/stdc++.h>

using namespace std;
int input[33000];
int potency[33000];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int corners = (int)pow(2, n);
        for(int i = 0; i < corners; i++)
            scanf("%d", &input[i]);
        for(int i = 0; i < corners; i++)
        {
            int sum = 0;
            for(int j = 0; j < n; j++)
            {
                int mask = 1 << j;
                sum += input[i ^ mask];
            }
            potency[i] = sum;
        }
        int ans = 0;
        for(int i = 0; i < corners; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int mask = 1 << j;
                ans = max(ans, potency[i] + potency[i ^ mask]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
