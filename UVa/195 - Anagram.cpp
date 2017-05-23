#include <bits/stdc++.h>

using namespace std;
bool compare(string, string);

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        string s1;
        cin >> s1;
        vector<string> perm;
        sort(s1.begin(), s1.end());
        do
        {
            perm.push_back(s1);
        } while(next_permutation(s1.begin(), s1.end()));
        sort(perm.begin(), perm.end(), compare);
        for(int i = 0; i < (int)perm.size(); i++)
            cout << perm[i] << endl;
    }
    return 0;
}

bool compare(string s1, string s2)
{
    if(s1.size() < s2.size())
        return true;
    for(string::const_iterator lit = s1.begin(), rit = s2.begin(); lit != s1.end() && rit != s2.end(); lit++, rit++)
    {

        if(tolower(*lit) == tolower(*rit))
        {
            if(isupper(*lit) && islower(*rit)) return true;
            else if(isupper(*rit) && islower(*lit)) return false;
            else continue;
        }
        else if(tolower(*lit) < tolower(*rit))
            return true;
        else if(tolower(*lit) > tolower(*rit))
            return false;
    }
    return false;
}
