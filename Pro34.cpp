#include "Pro34.h"
#include <iostream>
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H
using namespace std;

int Pro34::mutiplyN(int *startPoi , int counts , int n , int *nums , int nowMax)
{
    int rs;
    while(*startPoi < counts)
    {
        //³Ën
        rs = nums[*startPoi] * n;
        if(rs > nowMax)
            return rs;
        *startPoi += 1;
    }
}

void Pro34::findUglyNum()
{
    int uglyNum[1500];
    int counts = 0;
    int m2Start = 0, m3Start = 0, m5Start = 0;
    int nowMax = 1 , nowMin = 1;
    int rs2 , rs3 , rs5;
    if(counts == 0)
        uglyNum[0] = 1;
    counts++;
    while(counts < 1500)
    {
        rs2 = mutiplyN(&m2Start , counts , 2 , uglyNum , nowMax);
        rs3 = mutiplyN(&m3Start , counts , 3 , uglyNum , nowMax);
        rs5 = mutiplyN(&m5Start , counts , 5 , uglyNum , nowMax);
        nowMin = mmin(rs2 , mmin(rs3 , rs5));
        uglyNum[counts] = nowMin;
        nowMax = nowMin;
        counts++;
    }
    for(int i = 0; i < 1500; i++)
        cout<<uglyNum[i]<<endl;
}
