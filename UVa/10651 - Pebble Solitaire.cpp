#include <bits/stdc++.h>

using namespace std;
int setBit(int, int);
int resetBit(int, int);
bool checkBit(int, int);
int setBitChecker(int);
int func(int);
int dp[(1 << 12) + 2];
bool vis[(1 << 12) + 2];

int main()
{
    int n;
    scanf("%d", &n);
    memset(vis, false, sizeof vis);
    while(n--)
    {
        string s;
        cin >> s;
        int mask = 0;
        for(int i = 0; i < 12; i++)
            if(s[i] == 'o')
                mask = setBit(mask, 11 - i);
        printf("%d\n", func(mask));
    }
    return 0;
}

int setBit(int n, int pos) {return n | (1 << pos);}
int resetBit(int n, int pos) {return n & ~(1 << pos);}
bool checkBit(int n, int pos) {return n & (1 << pos);}

int func(int mask)
{
    if(vis[mask]) return dp[mask];
    int ret1 = 999999, ret2 = 999999, ans;
    for(int i = 0; i < 12; i++)
    {
        if(checkBit(mask, i))
        {
            if(i < 10 && checkBit(mask, i + 1) && !checkBit(mask, i + 2))
            {
                int newMask = resetBit(mask, i);
                newMask = resetBit(newMask, i + 1);
                newMask = setBit(newMask, i + 2);
                ret1 = func(newMask);
            }
            if(i > 1 && checkBit(mask, i - 1) && !checkBit(mask, i - 2))
            {
                int newMask = resetBit(mask, i);
                newMask = resetBit(newMask, i - 1);
                newMask = setBit(newMask, i - 2);
                ret2 = func(newMask);
            }
        }
    }
    ans = setBitChecker(mask);
    if(ret1 < 999999) ans = min(ans, ret1);
    if(ret2 < 999999) ans = min(ans, ret2);
    vis[mask] = true;
    dp[mask] = ans;
    return dp[mask];
}

int setBitChecker(int n)
{
    int ans = 0;
    while(n)
    {
        if(n & 1) ans++;
        n = n >> 1;
    }
    return ans;
}
