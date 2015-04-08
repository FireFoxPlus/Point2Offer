#include "preInclude.h"

bool Pro3_2::findInMatrix(int (*vals)[4] , int height , int width , int target)
{
    if(vals == NULL)
        return false;
    int line = 0 , col = width - 1;
    while(line < height && col > 0)
    {
        if(vals[line][col] == target)
            return true;
        if(vals[line][col] > target)
            col--;
        if(vals[line][col] < target)
            line++;
    }
    return false;
}
