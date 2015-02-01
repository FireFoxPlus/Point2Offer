#include "Pro14.h"
//将奇数置于偶数之前
void Pro14::swapOdd(int *values , int length , Judge judge){
    int pre = 0 , tail = length - 1;
    while(pre < tail){
        if(judge(values[pre]))
            pre++;
        else if(!judge(values[tail])){//tail所指为偶数
                tail--;
                continue;
                }
        else{
            int  tmp = values[pre];
            values[pre] = values[tail];
            values[tail] = tmp;
            }
        }
}
//是否是奇数
bool isOdd(int value){
    return value % 2 ? 1 : 0;
}
