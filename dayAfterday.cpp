#include "dayAfterday.h"
#include <iostream>

using namespace std;

bool isLeapYear(int year)
{
    bool rs = false;
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        rs = true;
    return rs;
}

void whichDay()
{
    int year , month , day , whichArry;
    int dayAfter;
    cout<<"year"<<endl;
    cin>>year;
    if(isLeapYear(year))
        whichArry = 2;
    else
        whichArry = 1;
    cout<<"month"<<endl;
    cin>>month;

    cout<<"day"<<endl;
    cin>>day;

    cout<<"the day after"<<endl;
    cin>>dayAfter;
    day += dayAfter;

    while(day > days[whichArry][month])
    {
         if(month == 12)
         {
            day -= days[whichArry][month];
            month = 1;
            year += 1;
            if(isLeapYear(year))
                whichArry = 2;
            else
                whichArry = 1;
        }
        else
        {
            day -= days[whichArry][month];
            month++;
        }
    }
    cout<<year<<'/'<<month<<'/'<<day<<endl;
}
