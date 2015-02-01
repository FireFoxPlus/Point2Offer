#include <iostream>
#include <cstring>
#include <memory>
#include "Pro22.h"
using namespace std;

int main()
{
    int a[] = {1 , 2 , 3 , 4 , 5};
    int b[] = {1 , 2 , 3 , 4 , 5};
    Pro22<int> obp;
    if(obp.judge(a , b , 5)){
        cout<<"true"<<endl;
    }
    else
        cout<<"false"<<endl;
}
