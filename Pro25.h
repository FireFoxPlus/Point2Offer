//�������к�Ϊĳһֵ��·��
//��Ŀ������һ�ö�������һ��������
//��ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·����
//�����ĸ��ڵ㵽Ҷ����������Ľڵ��γ�һ��·��
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H
#include <stack>

class Pro25
{
public :
    void PrintSumPath(bnode<int> *root , int sum);
    void printPath(bnode<int> *root , int sum);
    void printPath(bnode<int> *root , int sum , stack<bnode<int>*> &paths);
private :
    mstack<int> print_stack;
};

void printSTLStack(stack<bnode<int>*> &paths);
