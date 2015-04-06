#include <iostream>
#include <cstring>
#include <memory>
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H
#include "Pro47.h"

using namespace std;

int main()
{
    int vas[] = {5 , 7 , 2 , 4 , 9};
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5 - i - 1; j++)
            if(vas[j] < vas[j + 1])
            {
                int tmp = vas[j];
                vas[j + 1] = vas[j];
                vas[j] = tmp;
            }
}
