#include <bits/stdc++.h>

using namespace std;
struct solutions
{
    long long x, y;
    solutions(long long a, long long b) {x = a; y = b;}
};

int main()
{
    long long n;
    while(cin >> n && n)
    {
        vector<long long> factors;
        vector<solutions> answers;
        for(long long i = 1; i * i * i <= n; i++)
        {
            if(n % i == 0)
            {
                factors.push_back(i);
                //if(i != n/i)factors.push_back(n / i);
            }
        }
        for(long long i = 0; i < factors.size(); i++)
        {
            long long a = factors[i];
            long long b = n / a;
            long long det;
            if((12 * b) - (3 * a * a) >= 0)
            {
                det = (12 * b) - (3 * a * a);
                long long x1 = ((3 * a) + (sqrt(det) + .000000001)) / 6.0  + .000000001;
                long long y1 = x1 - a;
                if((x1 * x1 * x1) - (y1 * y1 * y1) == n && x1 >= 0 && y1 >= 0)
                    answers.push_back(solutions(x1, y1));
                long long x2 = ((3 * a) - (sqrt(det) + .000000001)) / 6.0 + .000000001;
                long long y2 = x2 - a;
                if((x2 * x2 * x2) - (y2 * y2 * y2) == n && x2 >= 0 && y2 >= 0)
                    answers.push_back(solutions(x2, y2));
            }
        }
        if(answers.size() == 0)
        {
            printf("No solution\n");
            continue;
        }
        long long y = LLONG_MAX, index = 0;
        for(int i = 0; i < answers.size(); i++)
        {
            if(answers[i].y < y)
            {
                y = answers[i].y;
                index = i;
            }
        }
        cout << answers[index].x << " " << answers[index].y << endl;
    }
    return 0;
}
