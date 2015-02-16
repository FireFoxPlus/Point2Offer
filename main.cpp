#include <iostream>
#include <cstring>
#include <memory>
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

#include <cstring>
#include "Pro36.h"


using namespace std;

int main()
{

    int a[] = {7 , 5 , 6 , 4};
    Pro36 obp;
    int rs = obp.getDsc(a , 4);
    cout<<rs;
}
