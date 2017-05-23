#include <bits/stdc++.h>

using namespace std;
struct Soldier
{
    int left, right;
    Soldier() {}
    Soldier(int left, int right) {this->left = left; this->right = right;}
};
Soldier arr[100010];

int main()
{
    int s, b;
    while(scanf("%d %d", &s, &b) && (s || b))
    {
        for(int i = 1; i <= s; i++)
            arr[i] = Soldier(i - 1, i + 1);
        arr[s].right = 0;
        for(int i = 0; i < b; i++)
        {
            int left, right;
            scanf("%d %d", &left, &right);
            int leftAlive = arr[left].left;
            int rightAlive = arr[right].right;
            if(leftAlive) {arr[leftAlive].right = rightAlive; printf("%d ", leftAlive);}
            else printf("* ");
            if(rightAlive) {arr[rightAlive].left = leftAlive; printf("%d\n", rightAlive);}
            else printf("*\n");
        }
        printf("-\n");
    }
    return 0;
}
