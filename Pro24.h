//二叉搜索树的后序遍历序列
//题目：输入一个整数数组，判断数组是不是某二叉搜索树的后序遍历结果。
//假设输入数组的任意两个数字互不相同
class Pro24
{
public :
    bool judgeSort(int *values , int length);
    int leftTree(int* start , int* ends , int rootValue);
    bool rightTree(int* start , int* ends , int rootValue);
};

class Pro24_2
{
public :
    bool isSortTree(char *str , int len);
};
