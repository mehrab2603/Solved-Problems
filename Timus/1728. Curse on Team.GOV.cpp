#include <bits/stdc++.h>
#define MAX 210

using namespace std;
map<string, int> mymap;
bool part[MAX][MAX][MAX];
string names[MAX];
int val[MAX];
string input[MAX];

int main()
{
    int n, rk, re;
    scanf("%d", &n);
    int num = 3;
    mymap["Efremov"] = 1;
    mymap["Kantorov"] = 2;
    names[1] = "Efremov";
    names[2] = "Kantorov";
    memset(part, false, sizeof part);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        vector<int> temp;
        for(int j = 0; j < x; j++)
        {
            string s1;
            cin >> s1;
            if(mymap.find(s1) == mymap.end())
            {
                mymap[s1] = num;
                names[num] = s1;
                num++;
            }
            temp.push_back(mymap[s1]);
        }
        if(x == 1) part[0][0][2] = true;
        else if(x == 2) {sort(temp.begin(), temp.end()); part[0][2][temp[1]] = true;}
        else {sort(temp.begin(), temp.end()); part[1][2][temp[2]] = true;}
        temp.clear();
    }
    scanf("%d %d", &re, &rk);
    int m;
    val[1] = re;
    val[2] = rk;
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        int pow;
        cin >> input[i];
        scanf("%d", &pow);
        if(mymap.find(input[i]) == mymap.end())
        {
            mymap[input[i]] = num;
            names[num] = input[i];
            num++;
        }
        val[mymap[input[i]]] = pow;
    }
    int ans = -999;
    string ansstr;
    bool flag = false;
    for(int i = 0; i < m; i++)
    {
        if(part[1][2][mymap[input[i]]])
        {
            if(part[0][2][mymap[input[i]]])
                {flag = true;}
            else
                {int faltu = ans; ans = max(ans, val[2] + val[mymap[input[i]]]); if(faltu != ans) ansstr = input[i];}
        }
        else
            {int faltu = ans; ans = max(ans, val[2] + val[mymap[input[i]]] + val[1]); if(faltu != ans) ansstr = input[i];}
    }
    if(flag && ans < 0) cout << "Fail" << endl;
    else cout << "Win" << endl << ansstr << endl;
    return 0;
}
