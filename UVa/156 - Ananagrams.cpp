#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> input, output, temp;
    string s1;
    while(cin >> s1 && s1 != "#")
    {
        input.push_back(s1);
        transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
        sort(s1.begin(), s1.end());
        temp.push_back(s1);
    }
    for(int i = 0; i < (int)temp.size(); i++)
    {
        bool flag = true;
        for(int j = 0; j < (int)temp.size(); j++)
        {
            if(i == j) continue;
            if(temp[i] == temp[j]) {flag = false; break;}
        }
        if(flag) output.push_back(input[i]);
    }
    sort(output.begin(), output.end());
    for(int i = 0; i < (int)output.size(); i++)
        cout << output[i] << endl;
    return 0;
}
