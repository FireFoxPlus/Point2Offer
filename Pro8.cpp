#include "Pro8.h"

int Pro8::findMin(int *values , int length){
    //如果是整体旋转，第一个数字即是最小
    if(values[0] < values[length - 1])
        return values[0];

     int endIndex = length - 1 , startIndex = 0;
     int midIndex;
     while(startIndex < endIndex){
           midIndex = (startIndex + endIndex) / 2;
            if(values[midIndex] > values[length - 1]){
                if(values[midIndex] < values[midIndex - 1])
                    return values[midIndex];
                startIndex = midIndex + 1;
                }
            else{
                if(values[midIndex] < values[midIndex - 1])
                    return values[midIndex];
                endIndex = midIndex - 1;}

    }
    return values[startIndex];
}
