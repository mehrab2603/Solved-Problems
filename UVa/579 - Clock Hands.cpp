#include <bits/stdc++.h>

using namespace std;

int main()
{
    int hh, mm;
    while(scanf("%d:%d", &hh, &mm))
    {
        if(hh == 0 && mm == 0) break;
        if(hh == 12) hh = 0;
        double hhd = (hh * 360) / (12 * 1.00);
        double mmd = (mm * 360) / (60 * 1.00);
        double offset = (1.0 / 60) * mm;
        hhd += (offset * 360) / (12 * 1.00);
        double ans = hhd - mmd;
        if(ans  < 0) ans *= -1;
        if(ans > 180) ans = 360 - ans;
        printf("%.3lf\n", ans);
    }
    return 0;
}
