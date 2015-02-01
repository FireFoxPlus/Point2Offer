#include "Pro17.h"

int * Pro17::mergeList(int *fir , int firlen , int *sec , int seclen){
    int * rs = new int[firlen + seclen];
    int *firEnd = fir + firlen  - 1 , * secEnd = sec + seclen - 1;
    int i = 0;
    while(i < firlen + seclen){
    if(fir > firEnd){
        //复制第二个list
        while(!(sec > secEnd)){
            rs[i] = *sec;
            i++;
            sec++;
            }
    }
    else if(sec > secEnd){
        //复制第一个list
        while(!(fir > firEnd)){
            rs[i] = *fir;
            i++;
            fir++;
            }
        }
    else{
        if(*fir > *sec){
            rs[i] = *sec;
            i++;
            sec++;
        }
        else{
            rs[i] = *fir;
            i++;
            fir++;
        }
        }
    }
        return rs;
    }
