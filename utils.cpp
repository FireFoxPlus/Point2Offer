#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

#include <time.h>
#include <stdlib.h>
//val1����val2����true
bool small(int val1 , int val2)
{
    return val1 > val2 ? true : false;
}


void mswap(int *val1 , int * val2)
{
    int tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

int getRandom(int range)
{
    srand((int)time(NULL));
    int rs = rand();
    return rs % range;
}
