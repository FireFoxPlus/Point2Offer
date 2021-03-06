#include "fastSort.h"
#include <iostream>

#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

//返回的是数组下标
int partion(int *values , int length)
{
    int rs = getRandom(length - 1);
    mswap(&values[rs] , &values[length - 1]);

    if(values == NULL || length <= 0)
        return -1;
    int counts = -1;
    for(int i = 0; i < length; i++)
    {
        if(values[i] < values[length - 1])
        {
            counts++;
            if(counts != i)
                mswap(&values[i] , &values[counts]);
        }
    }
    counts++;
    mswap(&values[length - 1] , &values[counts]);
    return counts;
}

void fastSort(int *values , int length)
{
    if(length == 1)
        return;
    if(length == 2)
    {
        int tmp = values[0];
        values[0] = values[0] < values[1] ? values[0] : values[1];
        values[1] = tmp > values[1] ? tmp : values[1];
        return;
    }

    int split = partion(values , length);

    if(split > 0)
        fastSort(values , split);
    if(split + 1 < length)
        fastSort(values + split + 1 , length - split -1);
}
