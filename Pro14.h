//��������˳��ʹ����λ��ż��ǰ��
//��Ŀ������������Ԫ��˳��ʹ������λ�������ǰ�벿�֣�
//ż��λ������ĺ�벿��
#include <vector>
using namespace std;
bool isOdd(int value);

class Pro14
{
public :
    typedef bool (*Judge)(int);
    void swapOdd(int *values , int length , Judge judge);
    inline void oddBeforeEven(vector<int> &vals);
};

void Pro14::oddBeforeEven(vector<int> &values)
{
    int start = 0 , ends = values.size();
    while(start < ends)
    {
        while(values[start] % 2 == 1)
            start++;
        while(values[ends] % 2 == 0)
            ends--;
        if(start < ends)
        {
            values[start] = values[start] + values[ends];
            values[ends] = values[start] - values[ends];
            values[start] = values[start] - values[ends];
        }
    }
}
