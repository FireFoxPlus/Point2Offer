#include "Pro42.h"
#include <cstring>

char* Pro42::reverseSenten(char * val)
{
    int len = strlen(val);
    char *copys = new char[len + 1];
    strcpy(copys , val);
    copys[len] = '\0';
    //句子反转
    for(int i = 0; i < len / 2; i++)
    {
        char tmp = copys[i];
        copys[i] = copys[len - 1 - i];
        copys[len - 1 - i] = tmp;
    }
    int reverLen = 0;
    //单词反转
    for(int i = 0; copys[i] != '\0'; i++)
    {
        if(copys[i] == ' ' || i == len - 1)
        {
            reverseWord(&copys[i] -  reverLen , reverLen);
            reverLen = 0;
        }
        else
            reverLen++;
    }
    return copys;
}

void Pro42::reverseWord(char *val , int len)
{
    for(int i = 0; i < len / 2; i++)
    {
        char tmp = val[i];
        val[i] = val[len - 1 - i];
        val[len - 1 - i] = tmp;
    }
}

void Pro42::leftReverse(char *val , int length , int left)
{
    reverseWord(val , length);
    reverseWord(val , length - left);
    reverseWord(val + length - left , left);
}
