//Pro32:1到n的整数中，1出现的次数
//把数组排成最小的数
//输入一个正整数数组，把整数里所有数字拼接成一个数，输出所能拼接得到的最小数
bool Compare(int val1 , int val2);
void tailCopy(char*rs , int val);

class Pro33
{
public :
    Pro33()
    {
        mins = 0x08000000;
    }
    void getMinInArray(int *values , int length , int cur , char *rs);
    char *appendChar(char *rs , int val);
    int getMins()
    {
        return mins;
    }
    void getMinsInArray_2(int *values , int length);
    friend bool Compare(int val1 , int val2);
    friend void tailCopy(char*rs , int val);
private :
    int mins;
};

