#include <iostream>
#include <cstring>
#include <memory>
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H
#include "Pro43.h"

using namespace std;

int main()
{
    Pro43 obp;
    int *rs = obp.getPossi_2(2);
    for(int i = 1; i <= 12; i++)
        cout<<rs[i]<<endl;
}
