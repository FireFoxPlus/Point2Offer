#include <iostream>
#include <cstring>
#include <memory>
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

#include <cstring>
#include "Pro33.h"


using namespace std;

int main()
{
    int a[] = {3 , 32 , 321};
    int b[] = {4 , 5 , 3 , 1 , 2};
    Pro33 obp;
    obp.getMinsInArray_2(b , 5);
    cout<<obp.getMins();
}
