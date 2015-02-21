#include "Pro44.h"
#include "fastSort.h"
#include <iostream>

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
