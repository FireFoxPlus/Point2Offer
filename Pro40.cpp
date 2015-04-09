#include "Pro40.h"
#include <iostream>

using namespace std;

void Pro40::appearOnce(int *value , int length)
{
    int rs = 0;
    for(int i = 0; i < length; i++)
        rs = rs ^ value[i];
    int flage = 0x00000001;
    while(true)
    {
        if((rs & flage) == 1)
            break;
        flage = flage<<1;
    }
    rs = 0;
    for(int i = 0; i < length; i++)
    {
        if(value[i] & flage)
            rs = rs ^ value[i];
    }
    cout<<"1st:"<<rs<<endl;
    rs = 0;
    for(int i = 0; i < length; i++)
    {
        if(! (value[i] & flage))
            rs = rs ^ value[i];
    }
    cout<<"2nd:"<<rs<<endl;
}


void Pro40_2::appearOnce(int *vals , int len)
{
    int rs = 0;
    for(int i = 0; i < len; i++)
        rs ^= vals[i];
    int mask = 0x00000001;
    for(int i = 0; i < 32; i++)
    {
        if((mask & rs) != 0)
            break;
         mask = mask << 1;
    }
    int one = 0 , two = 0;
    for(int i = 0; i < len; i++)
    {
        if(vals[i] & mask != 0)
            one ^= vals[i];
        else
            two ^= vals[i];
    }
    cout<<"first one"<<one<<endl;
    cout<<"second one"<<two<<endl;
}
