#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

long long primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
long long arr[101];
vector<long long> ans;

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        long long x;
        cin >> x;
        memset(arr, 0, sizeof(arr));
        for(long long i = 2; i <= x; i++)
        {
            long long num = i;
            for(long long j = 0; primes[j] <= num ; j++)
            {
                if(num % primes[j] == 0)
                {
                    if(arr[primes[j]] == 0) ans.push_back(primes[j]);
                    while(num % primes[j] == 0)
                    {
                        arr[primes[j]]++;
                        num = num / primes[j];
                    }
                }
            }
        }
        printf("Case %d: %lld =", ++caseno, x);
        for(int i = 0; i < ans.size(); i++)
        {
            printf(" %lld (%lld)", ans[i], arr[ans[i]]);
            if(i < ans.size() - 1) printf(" *");
        }
        printf("\n");
        ans.clear();
    }

    return 0;
}
