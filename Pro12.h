//打印1到最大的n位数
//题目：输入数字n，按顺序打印从1最大的n位十进制数，
//比如输入3，则打印1,2,3一直到最大的3位数999
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

class Pro12
{
public :
    Pro12(int m):num(m){}
    Pro12(){}
    BigNum &getBigNum();
    void printToM(char* rs , int n ,int m);
    inline void printToN(int n);
    inline void strAdd(char *rs,  char *addNum);
private :
    BigNum num;
};

void Pro12::strAdd(char* rs , char *addNum)
{
    int i;
    for(i = 0; addNum[i] != '\0'; i++)
    {
        if(addNum[i] != '0')
            break;
    }
    if(addNum[i] == '\0')
        return;
    char* carry = new char[strlen(rs) + 1];
    memset(carry , '0' , strlen(rs) + 1);
    carry[strlen(rs)] = '\0';
    int lenRs = strlen(rs) - 1 , lenAdd = strlen(addNum) - 1 ,
                lenCarry = strlen(carry) - 1;
    while(lenRs >= 0 && lenAdd >= 0)
    {
        int tmp = rs[lenRs] - '0' + addNum[lenAdd] - '0';
        rs[lenRs] = tmp % 10 + '0';
        carry[lenCarry] = tmp / 10 + '0';
        lenRs--;
        lenAdd--;
        lenCarry--;
    }
    for(i = 0; carry[i] != '\0'; i++)
    {
        carry[i] = carry[i + 1];
    }
    carry[i - 1] = '0';
    strAdd(rs , carry);
    delete[] carry;
}

void Pro12::printToN(int n)
{
    char* num = new char[n + 1];//最后一位为'\0'
    char* last = new char[n + 1];
    memset(last , '9' , n + 1);
    memset(num , '0' , n + 1);
    last[n] = '\0';
    num[n] = '\0';
    while(strcmp(last , num))
    {
        char add[] = "1";
        strAdd(num , add);
        cout<<num<<endl;
    }
    delete[] last;
}
