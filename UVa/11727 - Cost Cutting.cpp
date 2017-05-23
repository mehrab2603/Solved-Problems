#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int T,i,j,count=0;
    cin>>T;
    int sal[3];
    for(i=0; i<T; i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>sal[j];
        }
        sort(sal, sal+3);
        cout<<"Case "<<++count<<": "<<sal[1]<<endl;
    }
    return 0;
}
