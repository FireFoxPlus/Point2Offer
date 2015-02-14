#include "Pro30.h"
#include "fastSort.h"

#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

#include <iostream>

using namespace std;

void Pro30::printPreK(int k )
{
    for(int i = 0; i < k; i++)
        cout<<values[i];
}

void Pro30::foundMinK(int * value_ , int length_ , int k)
{
    if(value_ == NULL || length <= 0)
        return;
    int rs = partion(value_ , length_);
    if(rs + 1 == k)
        return;
    if(rs + 1 > k)
        foundMinK(value_ , rs + 1 , k);
    else
        foundMinK(value_ + rs + 1 , length_ - rs - 1 , k - rs - 1);
}

void Pro30::foundMinK_2(int* value_ , int length_ , int k , bool (*judge)(int val1 , int val2))
{
    int *MinK = new int[k];
    int counts_contain = 0 , counts_input;
    for(counts_input = 0; counts_input < length_; counts_input++)
    {
        if(counts_contain < k)
        {
            MinK[counts_contain] = value_[counts_input];
            SortContain(MinK , counts_contain);
            counts_contain++;
        }
        else
        {
           if(judge(MinK[0] , value_[counts_input]))
           {
                MinK[0] = value_[counts_input];
                SortContain(MinK , k - 1);
           }
        }
    }

    for(int i = 0; i < k; i++)
        cout<<MinK[i];
}

//len是下标的上界
void Pro30::SortContain(int *vals , int lens)
{
    if(lens < 0)
        return;
    int cur = lens;
    while(cur >= 0)
    {
        if(cur * 2 + 1 <= lens)
            if(vals[cur] < vals[cur * 2 + 1])
                mswap(&vals[cur] , &vals[cur * 2 + 1]);
        if(cur * 2 + 2 <= lens)
            if(vals[cur] < vals[cur * 2 + 2])
                mswap(&vals[cur] , &vals[cur * 2 + 2]);
        cur--;
    }
}
