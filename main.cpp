#include <iostream>
#include <cstring>
#include <memory>
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

#include "Pro31.h"


using namespace std;

int main()
{
    int a[] = {1 , -2 , 3 , 10 , -4 , 7 , 2 , -5};
    Pro31 obp;
    cout<<obp.MaxSub(a , 8)<<endl;
    cout<<obp.MaxInN(a , 8 , 8);
}
