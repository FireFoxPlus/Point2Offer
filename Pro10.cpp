#include "Pro10.h"

//此版本的不足在于，如果num为负数，则会死循环
int Pro10::numOfOne(int num){
        int rs = 0;
        while(num != 0){
            if(num & 1)
                rs++;
            num >>= 1;
        }
        return rs;

}
//改进版，移动1而不是原数字
int Pro10::numOfOne2(int num){
    int rs = 0;
    int i = 1;
    while(i){
        if(num & i)
            rs++;
        i <<= 1;
    }
    return rs;
}
//再改进，依据原理： a&(a-1)将消去a最右端的1
int Pro10::numOfOne3(int num){
    int rs = 0;
    while(num){
        num &= num - 1;
        rs++;
    }
    return rs;

}
