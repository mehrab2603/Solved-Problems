#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin >> n, n)
    {
        int lo = 1, hi = ((int)ceil(n / 4.0)) * 4;
        vector<int> serial;
        serial.push_back(hi);
        hi--;
        while(lo < hi)
        {
            serial.push_back(lo++);
            serial.push_back(lo++);
            serial.push_back(hi--);
            serial.push_back(hi--);
        }

        printf("Printing order for %d pages:\n", n);
        int page = (int)ceil(n / 4.0);
        for(int i = 1; i <= page; i++)
        {
            int fl, fr, bl, br;
            fl = serial[i * 4 - 4];
            fr = serial[i * 4 - 3];
            bl = serial[i * 4 - 2];
            br = serial[i * 4 - 1];
            //cout << "page: " << i << " fl: " << fl << " fr: " << fr << " bl: " << bl << " br: " << br << endl;
            if(fl <= n || fr <= n)
            {
                printf("Sheet %d, front: ", i);
                if(fl > n) printf("Blank, ");
                else printf("%d, ", fl);
                if(fr > n) printf("Blank\n");
                else printf("%d\n", fr);
            }
            if(bl <= n || br <= n)
            {
                printf("Sheet %d, back : ", i);
                if(bl > n) printf("Blank, ");
                else printf("%d, ", bl);
                if(br > n) printf("Blank\n");
                else printf("%d\n", br);
            }
        }
    }
    return 0;
}
