//�������к�Ϊĳһֵ��·��
//��Ŀ������һ�ö�������һ��������
//��ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·����
//�����ĸ��ڵ㵽Ҷ����������Ľڵ��γ�һ��·��
#include "utils.h"
class Pro25
{
public :
    void PrintSumPath(bnode<int> *root , int sum);
    void printPath(bnode<int> *root , int sum);
private :
    mstack<int> print_stack;
};
