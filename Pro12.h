//��ӡ1������nλ��
//��Ŀ����������n����˳���ӡ��1����nλʮ����������������3�����ӡ1,2,3һֱ������3λ��999
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
