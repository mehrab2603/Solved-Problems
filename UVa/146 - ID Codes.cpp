#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1;
    while(cin >> s1 && s1 != "#")
    {
        string ans = "";
        if(next_permutation(s1.begin(), s1.end())) ans = s1;
        if(ans == "") cout << "No Successor" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
