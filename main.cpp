#include <iostream>
#include <cstring>
#include <memory>
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

#include "Pro30.h"


using namespace std;

int main()
{
    int a[] = {3 , 3 , 3 , 4 , 3 , 2 , 2 , 3};
    Pro30 obp(a , 8);
    obp.foundMinK_2(a , 8 , 7 , small);
}
