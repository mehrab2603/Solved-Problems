#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
long long banana(int, int, int, int);
long long dp[200][100];
long long arr[200][100];

int main()
{
    int n;
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++) //getting input in rows 0 to n - 1
            {
                if(j <= i) scanf("%I64d", &arr[i][j]); // getting inputs in row
                else arr[i][j] = 0; // after a row is filled up with input, filling the rest of the current row with 0 and then moving onto next row
            }
        }
        for(int i = n, k = n - 1; i < (2 * n) - 1; i++, k--) //getting input in rows n to (2n -1) - 1
        {
            for(int j = 0; j < n; j++)
            {
                if(j < k)scanf("%I64d", &arr[i][j]);
                else arr[i][j] = 0; // after a row is filled up with input, filling the rest of the current row with 0 and then moving onto next row
            }
        }
        //fill(&dp[0][0], &dp[0][0] + (&dp[n+2][n+2] - &dp[0][0]), -1); <--- should be faster, but not used
        memset(dp, -1, sizeof(dp)); // clearing dp with -1
        printf("Case %d: %I64d\n", ++caseno, banana(0, 0, (2 * n) - 1, n)); // calling the function and printing result
    }
    return 0;
}

long long banana(int i, int j, int r, int c)
{
    if(i >= 0 && i < r && j >= 0 && j < c) // if still inside the working area
    {
        if(dp[i][j] != -1) return dp[i][j]; // if dp is filled, no need to calculate again. just returning dp
        long long ret = 0;
        if(i < r/2) //moves for the first half rows
        {
            ret = max(ret, banana(i + 1, j, r, c) + arr[i][j]);
            ret = max(ret, banana(i + 1, j + 1, r, c) + arr[i][j]);
        }
        else //moves for the rest of the rows
        {
            ret = max(ret, banana(i + 1, j, r, c) + arr[i][j]);
            ret = max(ret, banana(i + 1, j - 1, r, c) + arr[i][j]);
        }
        dp[i][j] = ret;
        return dp[i][j];
    }
    else return 0;
}
