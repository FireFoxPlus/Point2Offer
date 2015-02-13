#include <iostream>
#include <cstring>
#include <memory>
#include "Pro29.h"
#include "fastSort.h"
using namespace std;

int main()
{
    int a[] = {2 , 3 , 3 , 4 , 3 , 2 , 2 , 3};
    Pro29 obp(a , 8);
    cout<<obp.MoreThanHalf_2(a , 8 , 4);
}
