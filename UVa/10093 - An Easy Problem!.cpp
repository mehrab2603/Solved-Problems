#include <bits/stdc++.h>

using namespace std;
int anyBaseToDecimal(char);

int main()
{
    string input;
    while(cin >> input)
    {
        while(input[0] == '-' || input[0] == '+' || input[0] == ' ') input.erase(input.begin());
        if(input == "0") {cout << 2 << endl; continue;}
        string temp = input;
        sort(temp.begin(), temp.end());
        int startBase = anyBaseToDecimal(temp[temp.length() - 1]);
        bool flag = false;
        for(int i = startBase + 1; i <= 62; i++)
        {
            int nMinusOne = i - 1, mod = 0;
            for(int j = 0; j< (int)input.length(); j++)
            {
                int currNumber = mod * i + anyBaseToDecimal(input[j]);
                mod = currNumber % nMinusOne;
            }
            if(mod == 0) {cout << i << endl; flag = true; break;}
        }
        if(!flag) cout << "such number is impossible!" << endl;
    }
    return 0;
}

int anyBaseToDecimal(char ch)
{
    if(isalpha(ch))
    {
        if(isupper(ch))
            return ch - 'A' + 10;
        else
            return ch - 'a' + 36;
    }
    else
        return ch - '0';
}
