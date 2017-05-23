#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1;
    while(getline(cin, s1) && s1 != "Game Over")
    {
        int sum = 0, roll = 0;
        for(int i = 0; roll < 20; i += 2)
        {
            if(s1[i] == 'X')
            {
                sum += 10;
                if(s1[i + 2] == 'X')
                    sum += 10;
                else sum += s1[i + 2] - '0';
                if(s1[i + 4] == 'X')
                    sum += 10;
                else if(s1[i + 4] == '/')
                    sum += 10 - s1[i + 2] + '0';
                else
                    sum += s1[i + 4] - '0';
                roll += 2;
            }
            else if(s1[i] == '/')
            {
                sum += 10 - s1[i - 2] + '0';
                if(s1[i + 2] == 'X' || s1[i + 2] == '/')
                    sum += 10;
                else sum += s1[i + 2] - '0';
                roll++;
            }
            else {sum += s1[i] - '0'; roll++;}
        }
        printf("%d\n", sum);
    }
    return 0;
}
