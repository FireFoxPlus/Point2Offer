#include "Pro29.h"
#include "fastSort.h"
#include <iostream>
int Pro29::MoreThanHalf_1()
{
    int value , counts = 0;
    for(int i = 0; i < length; i++)
    {
        if(counts == 0)
            value = values[i];
        if(counts > 0 && values[i] != value)
            counts--;
        if(counts > 0 && values[i] == value)
            counts++;
    }
    return value;
}
//既然超过一半，那么将数组排序，那么出现次数超过一半的数字
//一定在n/2的位置上，也就是说，是第n/2大的数字
int Pro29::MoreThanHalf_2(int* value , int length_ , int goal)
{
    if(length_ <= 0 || value == NULL)
        return -1;
    int rs;
    int part = partion(value , length_);

    if(part + 1 == goal)
        return value[part];

    if(part + 1 > goal)
        rs = MoreThanHalf_2(value , part + 1 , goal);
    else
        rs = MoreThanHalf_2(value + part + 1 , length_ - part - 1 , goal - part - 1);
    return rs;
}
