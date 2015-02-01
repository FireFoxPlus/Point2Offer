#include "utils.h"
class Pro12{
public :
    Pro12(int m):num(m){
    }
    Pro12(){}
    BigNum &getBigNum();

    void printToM(char* rs , int n ,int m);
private :
    BigNum num;
};
