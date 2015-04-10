#include "Pro44.h"
#include "fastSort.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool Pro44::isStraight(int *vals , int length)
{
    int countZero = 0 , countMis = 0;
    if(vals == NULL)
        return false;
    fastSort(vals  , length);
    for(int i = 0; i < length; i++)
    {
        if(vals[i] == 0)
            countZero++;
        if(i != 0 && vals[i - 1] == vals[i])
            return false;
        if(i != 0 && vals[i - 1] != 0)
            countMis += vals[i] - vals[i - 1] - 1;
    }
    return countZero >= countMis;
}

bool Pro44_2::isStraight(int *vals , int len)
{
    bool rs = 0;
    int joker = 0;
    int counts = 0;
    sort(vals , vals + len);
    for(int i = 0; i < len; i++)
    {
        if(vals[i] == 0)
        {
            joker++;
            continue;
        }
        if(i != 0 && vals[i - 1] != 0)
        {
            counts += vals[i] - vals[i - 1] - 1;
        }
    }
    return joker >= counts;
}
