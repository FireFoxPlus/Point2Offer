//�ϲ��������������
//��Ŀ�����������������������
//�ϲ�����������ʹ�������еĽڵ���Ȼ�ǰ��յ��������
class Pro17
{
public :
    int * mergeList(int *fir , int firlen , int * sec , int seclen);
    inline int* merge2List(int * fir , int firlen , int* sec , int seclen);
};

int* Pro17::merge2List(int* fir , int firlen , int *sec , int seclen)
{
    int *rs = new int[firlen + seclen];
    int firStart = 0 , secStart = 0 , mergeStart = 0;
    while(firStart < firlen || secStart < seclen)
    {
        if(firStart < firlen && fir[firStart] < sec[secStart])
        {
            rs[mergeStart] = fir[firStart];
            mergeStart++;
            firStart++;
        }
        else if(secStart < seclen && sec[secStart] < fir[firStart])
        {
            rs[mergeStart] = sec[secStart];
            mergeStart++;
            secStart++;
        }
    }
    return rs;
}
