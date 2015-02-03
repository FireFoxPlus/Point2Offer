#include <iostream>
#include <cstring>
#include <memory>
#include "Pro24.h"
using namespace std;

int main()
{
    Pro24 obp;
    int values1[] = {5 , 7 , 6 , 9 , 11 , 10 , 8};
    int values2[] = {7 , 4 , 6 , 5};

    if(obp.judgeSort(values2 , 4))
        cout<<"yes";
    else cout<<"no";


}
