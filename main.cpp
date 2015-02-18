#include <iostream>
#include <cstring>
#include <memory>
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H
#include "Pro42.h"

using namespace std;

int main()
{
    char str[] = "abcdefg";
    Pro42 obp;
    obp.leftReverse(str , 7 , 2);
    for(int i = 0; i < 7; i++)
        cout<<str[i];


}
