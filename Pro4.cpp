#include "Pro4.h"
#include <iostream>
#include <cstring>
Pro4::Pro4(char *str)
{
    values = str;
}
char* Pro4::mreplace()
{
        char *rs = NULL;
        int itr = 0 , counts = 0;;
        if(values == NULL)
            return NULL;
        while(values[itr] != '\0')
        {
            if(values[itr] == ' ')
                counts++;
            itr++;
        }
        int length = strlen(values) + counts * 2;
        rs = new(char[length + 1]);
        rs[length] = '\0';
        char *p1;
        p1 = rs + length - 1;
        itr = strlen(values) - 1;
        while(itr >= 0)
        {
            if(values[itr] != ' ')
            {
                *p1 = values[itr];
                p1--;
                itr--;
            }
            else
            {
                *p1 = '0';
                p1--;
                *p1 = '2';
                p1--;
                *p1 = '%';
                p1--;
                itr--;
            }
        }
        return rs;
}
