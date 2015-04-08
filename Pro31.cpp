#include "Pro31.h"
#include <iostream>

using namespace std;

int Pro31::MaxSub(int *values , int length)
{
    int rs = 0;
    int maxs = values[0];
    for(int i = 0; i < length; i++)
    {
        rs += values[i];
        if(rs > maxs)
            maxs = rs;
        if(rs < 0)
            rs = 0;
    }
    return maxs;
}
//curÎªÏÂ±ê
int Pro31::MaxSub_2(int *values , int length , int cur)
{
    int preRs , rs;
    if(cur == 0)
        return values[cur];
    preRs = MaxSub_2(values , length , cur - 1);
    if(preRs <= 0)
        rs = values[cur];
    if(preRs > 0)
        rs  = values[cur] + preRs;
   return rs;
}

int Pro31::MaxInN(int *values , int length , int cur)
{
    int maxs = 0x80000000 , tmp;
    for(int i = 0; i < cur; i++)
    {
        tmp = MaxSub_2(values , length , i);
        if(tmp > maxs)
            maxs = tmp;
    }
    return maxs;
}

int Pro31_2::maxSum(int* vals , int len)
{
    int sum = 0 , maxs =  (1 << 31);
    for(int i = 0; i < len; i++)
    {
        sum += vals[i];
        if(sum < 0)
            sum = 0;
        if(sum > maxs)
        {
            maxs = sum;
        }
    }
    return maxs;
}
