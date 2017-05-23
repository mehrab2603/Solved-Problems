#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stack>

using namespace std;
void printBin(char);
long long power(int, long long);
long long Converter(string, int);
void finCon(long long, int);
stack<char> answer;

int main()
{
    int gbase, dbase;
    string number;
    while(cin >> number >> gbase >> dbase)
    {
        long long num = Converter(number, gbase);
        if(num == 0) {printf("      0\n"); continue;}
        finCon(num, dbase);
        while(answer.top() == '0') answer.pop();
        int blank = 7 - answer.size();
        if(blank < 0)
        {
            printf("  ERROR\n");
            while(!answer.empty())
                answer.pop();
            continue;
        }
        else
        {
            while(blank--)
                printf(" ");
        }

        while(!answer.empty())
        {
            printf("%c", answer.top());
            answer.pop();
        }
        printf("\n");
    }

    return 0;
}

long long Converter(string s, int base)
{
   long long sum = 0;
   long long countno = 0;
   for(int i = s.size() - 1; i >=0; i--)
   {
       long long num;
       if(s[i] == 'A') num = 10;
       else if(s[i] == 'B') num = 11;
       else if(s[i] == 'C') num = 12;
       else if(s[i] == 'D') num = 13;
       else if(s[i] == 'E') num = 14;
       else if(s[i] == 'F') num = 15;
       else num = s[i] - '0';
       sum = sum + (num * pow(base, countno));
       countno++;
   }
   return sum;
}

long long power(int x, long long y)
{
    if (y == 0) return 1;
    long long result = 1;
    for(int i = 0; i < y; i++) result = result * x;
    return result;
}

void finCon(long long num, int base)
{
    while(num)
    {
        int digit = num % base;
        num = num / base;
        if(digit < 10) answer.push(digit + '0');
        if(digit == 10) answer.push('A');
        else if(digit == 11) answer.push('B');
        else if(digit == 12) answer.push('C');
        else if(digit == 13) answer.push('D');
        else if(digit == 14) answer.push('E');
        else if(digit == 15) answer.push('F');
    }

}
