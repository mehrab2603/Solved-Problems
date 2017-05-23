#include <bits/stdc++.h>

using namespace std;
bool solved[101][10];
int penalty[101];
int problemPenalty[101][10];
short totalSolved[101];
struct compare
{
    bool operator () (int a, int b)
    {
        if(totalSolved[a] == totalSolved[b])
        {
            if(penalty[a] == penalty[b])
            {
                return a < b;
            }
            else return penalty[a] < penalty[b];
        }
        else return totalSolved[a] > totalSolved[b];
    }
};
set<int> submitted;
set<int, compare> ranked;

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    getchar();
    bool flag = false;
    while(t--)
    {
        if(flag) cout << endl;
        else flag = true;
        submitted.clear();
        ranked.clear();
        memset(solved, false, sizeof solved);
        memset(penalty, 0, sizeof penalty);
        memset(problemPenalty, 0, sizeof problemPenalty);
        memset(totalSolved, 0, sizeof totalSolved);
        string s1;
        while(getline(cin, s1) && s1 != "")
        {
            istringstream is(s1);
            int contestant, problem, time;
            char L;
            is >> contestant >> problem >> time >> L;
            submitted.insert(contestant);
            if(L == 'C')
            {
                if(!solved[contestant][problem])
                {
                    solved[contestant][problem] = true;
                    totalSolved[contestant]++;
                    penalty[contestant] += time + problemPenalty[contestant][problem];
                }
            }
            else if(L == 'I')
                if(!solved[contestant][problem])
                    problemPenalty[contestant][problem] += 20;
        }
        set<int>::iterator it;
        for(it = submitted.begin(); it != submitted.end(); it++)
            ranked.insert(*it);
        for(it = ranked.begin(); it != ranked.end(); it++)
            cout << *it << " " << totalSolved[*it] << " " << penalty[*it] << endl;
    }
    return 0;
}
