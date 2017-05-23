#include <stdio.h>
#include <string.h>
long leap_year(long);
int main()
{
    long t,caseno=0,date1, year1, date2, year2;
    char month1[10], month2[10];
    scanf("%ld", &t);

    while(t--)
    {
        long i,j,k,l, countno=0;

        scanf(" %s %ld , %ld", month1, &date1, &year1);
        scanf(" %s %ld , %ld", month2, &date2, &year2);
        for(i=year1+1;;i++)
            if (leap_year(i)) break;
        for(j=year2-1;;j--)
            if (leap_year(j)) break;

        if (i==j) countno=1;
        else if (j<i) countno=0;
        else
        {
            countno=((j-i)/4)+1;
            k=i+(100-(i%100));
            l=j-(j%100);
            if (k<j && l>i)
            {
                countno--;
                countno-=(l-k)/100;
            }
            k=i+(400-(i%400));
            l=j-(j%400);
            if (k<j && l>i)
            {
                countno++;
                countno+=(l-k)/400;
            }
        }
        if (year1!=year2)
        {
        if (leap_year(year1))
        {
            if(strcmp(month1,"January")==0 || strcmp(month1,"February")==0) ++countno;
        }

        if (leap_year(year2))
        {
            if(strcmp(month2,"January")!=0 && strcmp(month2,"February")!=0) ++countno;
            else if (strcmp(month2,"February")==0 && date2==29) ++countno;
        }
        }
        else
        {
            if(leap_year(year1))
            {
            if (strcmp(month1,"January")==0 || strcmp(month1,"February")==0)
            {
                if(strcmp(month2,"February")==0 && date2>28) ++countno;
                else if (strcmp(month2,"January")!=0 && strcmp(month2,"February")!=0) ++countno;
            }
            }
        }
        printf("Case %ld: %ld\n", ++caseno, countno);
    }
    return 0;
}

long leap_year(long a)
{
    if (a%400==0) return 1;
    else if (a%4==0 && a%100!=0) return 1;
    else return 0;
}
