#include "Pro24.h"

int Pro24::leftTree(int* start , int* ends , int rootValue){
    int counts = 0;
    while(start[counts] < rootValue){
        counts++;
        if(counts >= ends - start)
            break;
    }
    return counts;
}

bool Pro24::rightTree(int* start , int* ends , int rootValue){
    bool rs = true;
    if(ends == start)
        return true;
    while(start <= ends){
        if(*start > rootValue)
            start++;
        else{
            rs = false;
            break;
        }
    }
    return rs;
}
bool Pro24::judgeSort(int *values , int length){
    if(length == 0)
        return true;
    int rightStart = leftTree(&values[0] , &values[length - 1] , values[length - 1]);
    bool rs = rightTree(values + rightStart , values + length - 2 , values[length - 1]);
    if(!rs)
        return false;
    else
        return judgeSort(values , rightStart) && judgeSort(values + rightStart , length - rightStart - 1);
}
