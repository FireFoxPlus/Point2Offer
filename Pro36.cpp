#include "Pro36.h"
#include <iostream>
#include "stdlib.h"
#include <cstring>
using namespace std;
int Pro36::mmerge(int *val1 , int len1 , int *val2 , int len2)
{
    int rs = 0;
    int *val3 = new int[len1 + len2];
    int counts = 0 , valCount1 = 0 , valCount2 = 0;
    while(counts < len1 + len2)
    {
        if(valCount1 < len1 && valCount2 < len2)
        {
            if(val1[valCount1] > val2[valCount2])
            {
                val3[counts] = val1[valCount1];
                rs +=  len2 - valCount2;
                valCount1++;
            }
            else
            {
                val3[counts] = val2[valCount2];
                valCount2++;
            }
        }
        counts++;
        if(valCount1 >= len1)
        {
            while(valCount2 < len2)
            {
                val3[counts] = val2[valCount2];
                valCount2++;
                counts++;
            }
        }
        if(valCount2 >= len2)
        {
            while(valCount1 < len1)
            {
                val3[counts] = val1[valCount1];
                valCount1++;
                counts++;
            }
        }
    }
    for(int i = 0; i < len1 + len2; i++)
    {
        val1[i] = val3[i];
    }
    return rs;
}

int Pro36::getDsc(int *values , int length)
{
    if(length == 1)
        return 0;
    int leftCount = getDsc(values , length / 2);
    int rightCount = getDsc(values + length / 2 , length - length / 2);
    int mergeCount = mmerge(values , length / 2 , values + length / 2 , length - length / 2) + leftCount + rightCount;
    return mergeCount;
}

int Pro36_2::mergeSort(int *vals , int start , int ends)
{
    int rs = 0;
    if(ends - start > 0)
    {
        int mid = (ends + start) / 2;
        rs += mergeSort(vals , start , mid);
        rs += mergeSort(vals , mid + 1 , ends);
        rs += merges(vals , start , mid , ends);
    }
    return rs;
}

int Pro36_2::merges(int *vals , int start , int mid , int ends)
{
    int rs = 0;
    int *help = new int[ends - start + 1];
    memcpy(help , vals + start , sizeof(int) * (ends - start + 1));

    int firS =  start , secS = mid + 1;
    int counts = start;
    while(firS < mid + 1 && secS <= ends)
    {
        if(help[firS - start] < help[secS - start])
        {
            vals[counts] = help[firS - start];
            counts++;
            firS++;
        }
        else
        {
            vals[counts] = help[secS - start];
            counts++;
            secS++;
            rs += mid - firS + 1;
        }
    }
        while(firS < mid + 1)
        {
            vals[counts] = help[firS - start];
            counts++;
            firS++;
        }

    return rs;
}

int Pro36_2::getDsc(int *vals , int len)
{
    if(vals == NULL || len <= 0)
        return 0;
    int rs = mergeSort(vals , 0 , len - 1);
    return rs;
}
