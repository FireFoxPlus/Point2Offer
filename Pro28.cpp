#include "Pro28.h"
#include <iostream>

using namespace std;

void Pro28::Allout(char *cur)
{
    if(*cur == '\0')
        cout<<values<<endl;
    int i  = 0;
    while(cur[i] != '\0')
    {
        char tmp = cur[i];
        cur[i] = cur[0];
        cur[0] = tmp;

        Allout(cur + 1);

        tmp = cur[i];
        cur[i] = cur[0];
        cur[0] = tmp;
        i++;
    }
}
