#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int v,t;
    while(scanf("%d %d",&v,&t)==2)
    {
        if(v==0 && t==0)
        printf("0\n");
        else
        printf("%d\n",2*v*t);
    }
    return 0;
}
