#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
char s1[500000], s2[500000];

int main()
{
    while(scanf("%s %s", s1, s2) != EOF)
    {
        long long j = 0, countno = 0, flag = 0;
        for(long long i = 0; i < strlen(s1); i++)
        {
            for(; j < strlen(s2); j++)
            {
                if(s2[j] == s1[i])
                {
                    countno++;
                    j++;
                    break;
                }
                if(countno == strlen(s1)) break;
            }
            if(countno == strlen(s1)) {flag = 1; break;}
        }
        if(flag == 1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
