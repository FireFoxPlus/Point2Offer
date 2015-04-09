//和为s的两个数字VS和S的连续整数序列
//题目一：输入一个递增排序的数组和一个数字s，
//在数组中查找两个数，使得它们的和正好是s。
//题目二：输入一个正数s，打印出所有和为s的连续整数序列
class Pro41
{
public :
    void givenSum(int *values , int length , int sum);
    bool binarySearch(int *values , int length , int target);
    void givenSum_2(int *values , int length , int sum);
    void seqSum(int sum);
};

class Pro41_2
{
public :
    void getSumInArray(int *values , int len , int sum);
    void getSum(int sum);
};
