//������������˫������
//��Ŀ��������������������ö���������ת��Ϊһ�������˫������
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

class Pro27
{
public :
    bnode<int> *getLeftMost(bnode<int> *root);
    bnode<int> *getRightMost(bnode<int> *root);
    void tree2List(bnode<int> *root);
    void tree2List2(bnode<int> *root);
    void ConvertNode(bnode<int>* root , bnode<int>** LastInList);
};

class Pro27_2
{
public :
    void tree2List(bnode<int> *root);
    void midTour(bnode<int>*root , bnode<int>**tail);
};


