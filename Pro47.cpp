#include "Pro47.h"

int Pro47::doAdd(int a , int b)
{
    int rs , withOutCarry = 0 , Oldcarry , newCarry;
    withOutCarry = a ^ b;
    newCarry = Oldcarry = a & b;
    rs = withOutCarry;
    while(newCarry != 0)
    {
        newCarry = rs & Oldcarry;
        rs += Oldcarry<<1;
    }
    return rs;
    return rs;
}
