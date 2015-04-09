#include "Pro38.h"
#include <iostream>

int Pro38::sortCount(int *values , int length , int target)
{
    if(values == NULL || length == 0)
        return -1;
    int first = getFirst(values , length , target);
    int last = getLast(values , length , target);
    return last - first + 1;
}

int Pro38::getFirst(int *values , int length , int target)
{
    int start = 0, ends = length - 1 , mid = (start + ends) / 2;
    while(start < ends)
    {
        if(values[mid] < target)
            start = mid + 1;
        if(values[mid] >= target)
            ends = mid - 1;
        mid = (start + ends) / 2;
    }
    return start;
}


int Pro38::getLast(int *values , int length , int target)
{
    int start = 0, ends = length - 1 , mid = (start + ends) / 2;
    while(start < ends)
    {
        if(values[mid] <= target)
            start = mid + 1;
        if(values[mid] > target)
            ends = mid - 1;
        mid = (start + ends) / 2;
    }
    return start;
}

int Pro38_2::getFirst(int *vals , int len , int target)
{
    if(vals == NULL)
        return -1;
    int low = 0;
    int high = len - 1;
    int mid = (low + high) / 2;

    while(low < high)
    {
        if(vals[mid] >= target)
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
        else if(vals[mid] < target)
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
    }
    if(vals[low] == target)
        return low - 1;
    return low;
}

int Pro38_2::getLast(int *vals , int len , int target)
{
    if(vals == NULL)
        return -1;
    int low = 0;
    int high = len - 1;
    int mid = (low + high) / 2;

    while(low < high)
    {
        if(vals[mid] > target)
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }

        else if(vals[mid] <= target)
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
    }
    if(vals[low] == target)
        return low + 1;
    return low;
}

int Pro38_2::getTimes(int *vals , int len , int target)
{
    int firIndex = getFirst(vals , len , target);
    int lastIndex =  getLast(vals , len , target);
    if(firIndex == lastIndex)
        return 1;
    return lastIndex - firIndex - 1;
}
