//两个链表的第一个公共节点
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

template<typename T>
class Pro37
{
public :
    snode<T> *findFirstCommon(snode<T> *head1 , snode<T> *head2);
    int getLen(snode<T> *head);
};

template<typename T>
int Pro37<T>::getLen(snode<T> *head)
{
    int len = 0;
    while(head != NULL)
    {
        len++;
        head = head->getNext();
    }
    return len;
}

template<typename T>
snode<T> *Pro37<T>::findFirstCommon(snode<T> *head1 , snode<T> *head2)
{
    if(head1 == NULL || head2 == NULL)
        return;
    int len1 = getLen(head1) , len2 = getLen(head2);
    snode<T> *tmp1  , *tmp2 , **tmp;
    int forwards;
    if(len1 > len2)
    {
        forwards = len1 - len2;
        *tmp = tmp1;
    }
    else
    {
        forwards = len2 - len1;
        *tmp = tmp2;
    }
    while(forwards > 0)
    {
        *tmp = (*tmp)->getNext();
        forwards--;
    }
    while(tmp1 != tmp2 && tmp1 != NULL && tmp2 != NULL)
    {
        tmp1 = tmp1->getNext();
        tmp2 = tmp2->getNext();
    }
    return tmp1;
}

class Pro37_2
{
public :
    snode<int> *getFirstCommon(snode<int>* head1 , snode<int>* head2);
    int getLen(snode<int> *head);
};

