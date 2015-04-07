//数值的整数次方
//实现函数double Power(double base , int exponet),
//求base的exponent次方，不需要考虑大数问题
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
class Pro11
{
public :
    double power(double power , int ex);
    inline double abs_power(double power , int ex);
    inline double power_2(double base , int ex);
};

double Pro11::abs_power(double base , int ex)
{
    double rs = 1;
    for(int i  = 1; i <= ex; i++)
        rs *= base;
    return rs;
}

double Pro11::power_2(double base , int ex)
{
    double rs;
    if(ex == 0)
        rs = 1;
    else if(ex > 0)
        rs = abs_power(base , ex);
    else if(ex < 0)
    {
        if(abs(base - 0) < 1e-9)
        {
            cout<<"false"<<endl;
            return 0;
        }
        else
        {
            rs = abs_power(base , abs(ex));
            rs = 1 / rs;
        }
    }
    return rs;
}
