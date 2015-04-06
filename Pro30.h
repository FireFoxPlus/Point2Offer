//最小的k个数
//输入n个整数，输出最小的k个
class Pro30
{
public :
    Pro30(int *value_ , int length_)
    {
        values = value_;
        length = length_;
    }
    void printPreK(int k);
    void foundMinK(int * value_ , int length_ , int k);
    void foundMinK_2(int *value_ , int length_ , int k , bool (*judge)(int val1 , int val2));//´ó¸ù¶Ñ
    void SortContain(int *val , int length_);
private :
    int *values;
    int length;
};
