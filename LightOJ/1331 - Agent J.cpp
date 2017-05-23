#include <cstdio>
#include <cmath>
#define PI 2*acos(0.0)

int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        double r1, r2, r3;
        scanf("%lf %lf %lf", &r1, &r2, &r3);
        double a = r1 + r2;
        double b = r2 + r3;
        double c = r3 + r1;
        double s = (a + b + c) / 2;
        double triArea = sqrt(s * (s - a) * (s - b) * (s - c));
        double A = acos((b * b + c * c - a * a)/(2 * b * c));
        double B = acos((c * c + a * a - b * b)/(2 * c * a));
        double C = acos((a * a + b * b - c * c)/(2 * a * b));
        double segA = (A / (2 * PI)) * PI * r3 * r3;
        double segB = (B / (2 * PI)) * PI * r1 * r1;
        double segC = (C / (2 * PI)) * PI * r2 * r2;
        printf("Case %d: %lf\n", ++caseno, triArea - segA - segB - segC);
    }
    return 0;
}
