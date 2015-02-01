#include "Pro11.h"

double Pro11::power(double base , int ex){
    if(0 == base)
        return 0;
    if(0 == base && ex < 0)
        return false;
    if(ex == 0)
        return 1;
    int counts = 1;
    double rs = base;
    int exs = ex > 0 ? ex : -ex;
    while(counts < exs){
        rs = rs * base;
        counts++;
    }
    if(ex > 0)
        return rs;
    else return 1 / rs;
}
