//��������˳��ʹ����λ��ż��ǰ��
//��Ŀ������������Ԫ��˳��ʹ������λ�������ǰ�벿�֣�ż��λ������ĺ�벿��
bool isOdd(int value);

class Pro14
{
public :
    typedef bool (*Judge)(int);
    void swapOdd(int *values , int length , Judge judge);
};
