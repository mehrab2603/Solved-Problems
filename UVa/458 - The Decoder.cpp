#include <cstdio>
#include <cstring>

char s1[500000];

int main()
{
    while(gets(s1))
    {
        for(int i = 0; i < strlen(s1); i++)
        {
            putchar(s1[i] - 7);
        }
        printf("\n");
    }
    return 0;
}
