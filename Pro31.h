//连续子数组的最大和
//题目：输入一个整型数组，数组里有正有负。数组中一个或连续多个整数构成一个子数组，
//求所有子数组的和的最大值
class Pro31
{
public :
    int MaxSub(int *values , int length);
    int MaxSub_2(int *values , int length , int cur);
    int MaxInN(int *values , int length , int cur);
};
