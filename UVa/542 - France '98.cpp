#include <bits/stdc++.h>

using namespace std;

int main()
{
    string country[16];
    for(int i = 0; i < 16; i++)
        cin >> country[i];
    double mat[16][16];
    for(int i = 0; i < 16; i++)
        for(int j = 0; j < 16; j++)
            {int x; cin >> x; mat[i][j] = x / 100.0;}
    double sem[16];
    for(int i = 0; i < 16; i++)
    {
        int first, second1, second2;
        if(i % 4 == 0)
        {
            first = i + 1;
            second1 = i + 2;
            second2 = i + 3;
        }
        else if(i % 4 == 1)
        {
            first = i - 1;
            second1 = i + 1;
            second2 = i + 2;
        }
        else if(i % 4 == 2)
        {
            first = i + 1;
            second1 = i - 1;
            second2 = i - 2;
        }
        else
        {
            first = i - 1;
            second1 = i - 2;
            second2 = i - 3;
        }
        sem[i] = mat[i][first] * (mat[second1][second2] * mat[i][second1] + mat[second2][second1] * mat[i][second2]);
    }
    double fin[16];
    for(int i = 0; i < 8; i++)
    {
        int st, ed;
        if(i / 4 == 0) st = 0, ed = 3;
        else if(i / 4 == 1) st = 4, ed = 7;
        fin[i] = 0;
        for(int j = 0; j < 8; j++)
        {
            if(j >= st && j <= ed) continue;
            fin[i] += sem[i] * sem[j] * mat[i][j];
        }
    }
    for(int i = 8; i < 16; i++)
    {
        int st, ed;
        if(i / 4 == 2) st = 8, ed = 11;
        else st = 12, ed = 15;
        fin[i] = 0;
        for(int j = 8; j < 16; j++)
        {
            if(j >= st && j <= ed) continue;
            fin[i] += sem[i] * sem[j] * mat[i][j];
        }
    }
    double win[16];
    for(int i = 0; i < 16; i++)
    {
        int st, ed;
        if(i / 8 == 0) st = 0, ed = 7;
        else st = 8, ed = 15;
        win[i] = 0;
        for(int j = 0; j < 16; j++)
        {
            if(j >= st && j <= ed) continue;
            win[i] += fin[i] * fin[j] * mat[i][j];
        }
    }
    for(int i = 0; i < 16; i++) printf("%-10s p=%.2lf%%\n", country[i].c_str(), win[i] * 100);
    return 0;

}
