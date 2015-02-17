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
