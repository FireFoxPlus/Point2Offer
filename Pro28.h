//字符串的排列
//输入一个字符串，输出该字符串的全排列
#include <cstring>
class Pro28
{
public :
    Pro28(char *value)
    {
        int length = strlen(value);
        values = new char[length + 1];
        int i = 0;
        while(value[i] != '\0')
        {
            values[i] = value[i];
            i++;
        }
        values[i] = '\0';
    }
    void Allout(char *cur);
    char* getValue()
    {
        return values;
    }
private :
    char *values;
};
