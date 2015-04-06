//打印1到最大的n位数
//题目：输入数字n，按顺序打印从1最大的n位十进制数，比如输入3，则打印1,2,3一直到最大的3位数999
#include "utils.h"
class Pro12
{
public :
    Pro12(int m):num(m){}
    Pro12(){}
    BigNum &getBigNum();
    void printToM(char* rs , int n ,int m);
private :
    BigNum num;
};
