#include "Pro9.h"

int Pro9::fibo_1(int num){
    int pre1 , pre2 , rs;
    if(num == 0)
        return 0;
    else if(num == 1)
        return 1;
    else
    {
        int i = 0;
        while(i <= num){
            if(i == 0)
                pre1 = 0;
            else if(i == 1)
                pre2 = 1;
            else
            {
               rs = pre1 + pre2;
               pre1 = pre2;
               pre2 = rs;
            }
            i++;
        }
    }
    return rs;

}
