//�����г��ֳ���һ�������
//��������һ�����ֳ��ִ����������鳤��һ�룬�ҳ��������
class Pro29{
public :
    Pro29(int *value , int length_)
    {
        length = length_;
        values = new int[length];
        for(int i = 0; i < length; i++)
            values[i] = value[i];
    }

    int MoreThanHalf_1();
    int MoreThanHalf_2(int * value , int length_ , int goal);
private :
    int *values;
    int length;
};

class Pro29_2
{
public :
    int MoreThanHalf(int *vals , int len);
};
