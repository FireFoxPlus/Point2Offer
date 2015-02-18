#include "Pro41.h"
#include <iostream>
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H
using namespace std;

void Pro41::givenSum(int *values , int length , int sum)
{
    for(int i = 0; i < length; i++)
    {
        if(binarySearch(values , length , sum - values[i]))
        {
            cout<<values[i]<<endl<<sum - values[i];
            break;
        }
    }
}

bool Pro41::binarySearch(int *values , int length , int target)
{
    if(values == NULL)
        return false;
    int start = 0 , ends = length - 1 , mid = (start + length) / 2;

    while(start <= ends)
    {
        if(values[mid] == target)
            return true;
        if(values[mid] > target)
            ends = mid - 1;
        if(values[mid] < target)
            start = mid + 1;
        mid = (start + ends) / 2;
    }
    return false;
}

void Pro41::givenSum_2(int * values  , int length , int sum)
{
    int start = 0 , ends = length - 1;
    while(start < ends)
    {
        if(values[start] + values[ends] > sum)
            ends--;
        if(values[start] + values[ends] < sum)
            start++;
        if(values[start] + values[ends] == sum)
        {
            cout<<values[start]<<endl<<values[ends];
            break;
        }
    }
}

void Pro41::seqSum(int sum)
{
    mqueue<int> values;
    int tmp = 0;
    int i = 1;
    while(i <= sum)
    {
        if(tmp == sum)
            values.print();
        if(tmp > sum)
            tmp = tmp - values.deQueue();
        else
        {
            tmp += i;
            values.addQueue(i);
            i++;
        }
    }
}
