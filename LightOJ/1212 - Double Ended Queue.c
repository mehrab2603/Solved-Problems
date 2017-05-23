#include <cstdio>
#include <deque>
#include <iostream>

using namespace std;
deque<int> mydq;

int main()
{
    int t,caseno=0;
    scanf("%d", &t);
    while(t--)
    {
        int n,m;
        scanf("%d %d", &n, &m);
        printf("Case %d:\n",++caseno);
        while(m--)
        {
            string command;
            cin >> command;
            if(command == "pushLeft")
            {
                int x;
                scanf("%d", &x);
                if(mydq.size() == n)
                {
                    printf("The queue is full\n");
                    continue;
                }
                mydq.push_back(x);
                printf("Pushed in left: %d\n", x);
            }
            else if(command == "pushRight")
            {
                int x;
                scanf("%d", &x);
                if(mydq.size() == n)
                {
                    printf("The queue is full\n");
                    continue;
                }
                mydq.push_front(x);
                printf("Pushed in right: %d\n", x);

            }
            else if(command == "popLeft")
            {
                if(mydq.size() == 0)
                {
                    printf("The queue is empty\n");
                    continue;
                }
                printf("Popped from left: %d\n", mydq.back());
                mydq.pop_back();
            }
            else if(command == "popRight")
            {
                if(mydq.size() == 0)
                {
                    printf("The queue is empty\n");
                    continue;
                }
                printf("Popped from right: %d\n", mydq.front());
                mydq.pop_front();
            }
        }
        mydq.clear();
    }
    return 0;
}
