#include <cstring>
#include "Pro12.h"
#include <iostream>

using namespace std;

BigNum& Pro12::getBigNum(){
    return num;
}
void Pro12::printToM(char *num , int length , int index){
    if(index == length ){
        cout<<num<<endl;
        return;
        }
    int i;
    for(i = 0; i < 10; i++){
        num[index] = i + '0';
        printToM(num , length , index + 1);
    }
}
