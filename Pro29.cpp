#include "Pro29.h"
#include "fastSort.h"
#include <iostream>
int Pro29::MoreThanHalf_1()
{
    int value , counts = 0;
    for(int i = 0; i < length; i++)
    {
        if(counts == 0)
            value = values[i];
        if(counts > 0 && values[i] != value)
            counts--;
        if(counts > 0 && values[i] == value)
            counts++;
    }
    return value;
}
//��Ȼ����һ�룬��ô������������ô���ִ�������һ�������
//һ����n/2��λ���ϣ�Ҳ����˵���ǵ�n/2�������
int Pro29::MoreThanHalf_2(int* value , int length_ , int goal)
{
    if(length_ <= 0 || value == NULL)
        return -1;
    int rs;
    int part = partion(value , length_);

    if(part + 1 == goal)
        return value[part];

    if(part + 1 > goal)
        rs = MoreThanHalf_2(value , part + 1 , goal);
    else
        rs = MoreThanHalf_2(value + part + 1 , length_ - part - 1 , goal - part - 1);
    return rs;
}
