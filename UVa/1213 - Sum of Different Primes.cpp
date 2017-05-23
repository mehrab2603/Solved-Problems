#include <bits/stdc++.h>

using namespace std;
bool mark[1121];
long long dp[1121][190][15];
bool vis[1121][190][15];
int n, k, elements;
void seive(int);
bool isPrime(int);
long long func(int, int, int);
vector<int> primes;

int main()
{
    seive(1120);
    for(int i = 1; i <= 1120; i++)
        if(isPrime(i))
            primes.push_back(i);
    elements = primes.size();
    for(int i = 1; i <= 1120; i++)
        for(int j = 0; j < 15; j++)
            func(i, 0, j);
    while(scanf("%d %d", &n, &k) && (n || k))
    {
        cout << dp[n][0][k] << endl;
    }
    return 0;
}


void seive(int n)
{
    for(int i = 3; i * i <= n; i += 2) if(!mark[i]) for(int j = i * i; j <= n; j += i) mark[j] = true;
}

bool isPrime(int n)
{
    if(n == 1) return false;
    else if(n == 2) return true;
    else if(n % 2 == 0) return false;
    else return mark[n] == false;
}

long long func(int make, int index, int taken)
{
    if(index == elements && (make != 0 || taken != 0)) return 0;
    if(make == 0 && taken != 0) return 0;
    if(make != 0 && taken == 0) return 0;
    if(make == 0 && taken == 0) return 1;
    if(primes[index] > make) return 0;
    if(vis[make][index][taken]) return dp[make][index][taken];
    long long ret1, ret2;
    if(make - primes[index] >= 0)
    {
        ret1 = func(make - primes[index], index + 1, taken - 1);
        ret2 = func(make, index + 1, taken);
        dp[make][index][taken] = ret1 + ret2;
        vis[make][index][taken] = true;
        return dp[make][index][taken];
    }
    return 0;
}
