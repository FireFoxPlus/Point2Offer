#include <iostream>
#include <cstring>
#include <memory>
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H
#include "Pro38.h"

using namespace std;

int main()
{
    int a[] = {1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 3 , 4 , 5 , 6 , 6};
    Pro38 obp;
    cout<<obp.sortCount(a , 13 , 1);

}
