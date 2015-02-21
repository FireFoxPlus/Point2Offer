#include "Pro43.h"
#include <math.h>
#include <string.h>

int Pro43::getPossi(int counts , int sum , int target)
{
    if(target < counts)
        return 0;
    if(counts == 0)
        return 0;
    int rs = 0;
    for(int i = 1; i <= 6; i++)
    {
        sum += i;
        if(sum == target)
        {
            rs++;
            sum -= i;
            continue;
        }
        rs += getPossi(counts - 1 , sum , target);
        sum -= i;
    }
    return rs;
}

int *Pro43::getPossi_2(int counts)
{
    int *val1 = new int[6 * counts + 1];
    int *val2 = new int[6 * counts + 1];
    int *vals[2] = {val1 , val2};
    memset(val1 , 0 , sizeof(int) * (6 * counts + 1));
    memset(val2 , 0 , sizeof(int) * (6 * counts + 1));
    int  flag = 1;
    for(int i = 1; i <=6; i++)
    {
        val1[i] = 1;
        val2[i] = 1;
    }
    for(int i = 2; i <= counts; i++)
    {
        for(int k = 0; k < i; k++)
            (vals[flag])[0] = 0;
        for(int j = i; j <= 6 * i; j++)
        {
            (vals[flag])[j] = 0;
            for(int k = 1; k <= 6; k++)
            {
                if(j - k > 0)
                    (vals[flag])[j] += (vals[(flag + 1) % 2])[j - k];
            }
        }
        flag = (flag + 1) % 2;
    }
    return vals[(flag + 1) % 2];
}
