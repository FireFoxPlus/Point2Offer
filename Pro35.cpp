#include "Pro35.h"
#include <iostream>
using namespace std;
void Pro35::firstOnce(char *val)
{
    int hashs[256] = {0};
    char *tmp = val;
    while(*tmp != '\0')
    {
        hashs[*tmp]++;
        tmp++;
    }
    tmp = val;
    while(*tmp != '\0')
    {
        if(hashs[*tmp] == 1)
        {
            cout<<*tmp;
            break;
        }
        tmp++;
    }
}
