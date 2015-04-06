//调换数组顺序使奇数位于偶数前面
//题目：调整数组中元素顺序，使得奇数位于数组的前半部分，偶数位于数组的后半部分
bool isOdd(int value);

class Pro14
{
public :
    typedef bool (*Judge)(int);
    void swapOdd(int *values , int length , Judge judge);
};
