#include <iostream>
#include <cstring>
#include <memory>

#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

#include "Pro47.h"
#include "Pro11.h"
#include "Pro12.h"
#include "Pro14.h"
#include "Pro17.h"
#include "Pro18.h"
#include "Pro20.h"
#include "Pro21.h"
#include "Pro22.h"
#include "Pro24.h"
#include <vector>

using namespace std;

int main()
{
    Pro24_2 ob;
    char *val = "3415762";
    if(ob.isSortTree(val , 7))
        cout<<"legal";
    else
        cout<<"illegal";

}
