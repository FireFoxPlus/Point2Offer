#include <iostream>
#include <cstring>
#include <memory>
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H
#include "Pro44.h"

using namespace std;

int main()
{
    Pro44 obp;
    int a[] = {0,0,4,5,9};
    if(obp.isStraight(a))
        cout<<"straight";
    else
        cout<<"not";
}
