#include "Pro14.h"
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H
//����������ż��֮ǰ
void Pro14::swapOdd(int *values , int length , Judge judge)
{
    int pre = 0 , tail = length - 1;
    while(pre < tail)
    {
        if(judge(values[pre]))
            pre++;
        else if(!judge(values[tail]))//tail��ָΪż��
            {   tail--;
                continue;
            }
        else
            mswap(&values[pre] , &values[tail]);
    }
}
//�Ƿ�������
bool isOdd(int value)
{
    return value % 2 ? 1 : 0;
}
