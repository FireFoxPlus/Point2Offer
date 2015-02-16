#include "Pro36.h"

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
