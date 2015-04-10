//n个骰子的点数
//把n个骰子扔在地上，所有骰子朝上的一面点数之和为s，输入n，
//输出所有s出现的概率
class Pro43
{
public :
    int getPossi(int counts , int sum  , int target);
    int * getPossi_2(int counts);
};

class Pro43_2
{
public :
    int getPossi(int counts , int target , int nowSum);
};
