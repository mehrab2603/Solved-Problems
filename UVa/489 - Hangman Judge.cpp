#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
typedef long long vlong;

int main()
{

    while(1)
    {
        vlong x;
        cin >> x;
        if(x == -1) break;
        string input1, input2;
        cin >> input1;
        cin >> input2;
        int hangman = 7;
        int seen[26] = {};
        for(int j = 0; j < input2.length(); j++)
        {
            int lnum = input2[j] - 'a';
            int flag = 0;
            for(int i = 0; i < input1.length(); i++)
            {
                if(input1[i] == input2[j])
                {
                    flag = 1;
                    input1[i] = '0';
                }
            }
            for(int i = 0; i < input1.length(); i++)
            {
                if(input1[i] == '0')
                {
                    if(i == input1.length() - 1)
                    {
                        cout << "Round " << x << endl << "You win." << endl;
                        goto end;
                    }
                }
                else break;
            }
            if(flag == 0 && seen[lnum] == 0) hangman--;
            if(hangman == 0)
            {
                cout << "Round " << x << endl << "You lose." << endl;
                break;
            }
            if(seen[lnum] == 0) seen[lnum] = 1;
        }
        if(hangman != 0) cout << "Round " << x << endl << "You chickened out." << endl;
        end:;
    }
    return 0;
}
