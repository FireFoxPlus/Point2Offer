#include "Pro33.h"
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H
#include <cstring>
#include <algorithm>

void Pro33::getMinInArray(int *values , int length , int cur , char *rs)
{
    if(cur == length - 1)
    {
        rs = appendChar(rs , values[cur]);
        int int_rs = arrayToInt(rs);
        if(int_rs < mins)
            mins = int_rs;
        return;
    }
    for(int i = cur; i < length; i++)
    {
        mswap(&values[cur] , &values[i]);
        char *tmp = appendChar(rs , values[cur]);
        getMinInArray(values , length , cur + 1 , tmp);
        mswap(&values[cur] , &values[i]);
    }
    delete(rs);

}

char* Pro33::appendChar(char *preVal , int appenVal)
{
    char *rs = NULL;
    int pre_length;
    if(preVal == NULL)
        pre_length = 0;
    else
        pre_length = strlen(preVal);

    int length = pre_length + nDigits(appenVal) + 1;
    rs = new char[length];
    rs[length - 1] = '\0';
    if(preVal != NULL)
        strcpy(rs , preVal);//复制原串

    int after_length = nDigits(appenVal);
    int counts = 0;
    while(counts < after_length)
    {
        *(rs + length - 2 - counts) = (appenVal % 10) + '0';
        counts++;
        appenVal /= 10;
    }
    return rs;
}

void tailCopy(char *rs , int val)
{
    int length = nDigits(val);
   for(int i = 0; i < length; i++)
   {
       *(rs - i) = (val % 10) + '0';
       val /= 10;
   }
}

bool Compare(int val1 , int val2)
{
    int length = nDigits(val1) + nDigits(val2) + 1;
    char *tmp1 = new char[length];
    char *tmp2 = new char[length];
    tmp1[length - 1] = tmp2[length - 1] = '\0';
    tailCopy(tmp1 + length - 2 , val1);
    tailCopy(tmp1 + length - 2 - nDigits(val1) , val2);

    tailCopy(tmp2 + length - 2 , val2);
    tailCopy(tmp2 + length - 2 - nDigits(val2) , val1);
    int rs1 = arrayToInt(tmp1);
    int rs2 = arrayToInt(tmp2);
    delete(tmp1);
    delete(tmp2);
    return rs2 < rs1;
}

void Pro33::getMinsInArray_2(int *values , int length)
{
    sort(values , values + length , Compare);
    char *rs = NULL;
    char *tmp = NULL;
    for(int i = 0; i < length; i++)
    {
        tmp = rs;
        rs = appendChar(rs , values[i]);
        delete(tmp);
    }
    mins = arrayToInt(rs);
}
