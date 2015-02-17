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
