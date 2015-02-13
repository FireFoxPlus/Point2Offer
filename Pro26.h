#include "Complex_list.h"

template<typename T>
class Pro26
{
public :
    Complex_listNode<T>* getCopy();
    void fixSibling();
    void mcopy();
    Complex_listNode<T>* split();
private :
    Complex_listNode<T>* head;
};

template<typename T>
Complex_listNode<T>* Pro26<T>::getCopy()
{
    mcopy();
    fixSibling();
    Complex_listNode<T>* copy_head = split();
    return copy_head;
}

template<typename T>
void Pro26<T>::fixSibling()
{
    Complex_listNode<T> *tmp = head;
    bool isCopy = false;
    while(tmp != NULL)
    {
        if(isCopy && tmp->getSibling() != NULL)
            tmp->getSibling() = tmp->getSibling()->getNext();
        tmp = tmp->getNext();
        isCopy = !isCopy;
    }
}

template<typename T>
void Pro26<T>::mcopy()
{
    Complex_listNode<T> *cur = head;
    Complex_listNode<T> *tmp = NULL;

    while(cur != NULL)
    {
        tmp = new Complex_listNode<T>();
        tmp->setValue(cur->getValue());
        tmp->setNext(cur->getNext());
        tmp->setSibling(cur->setSibling());
        cur->setNext(tmp);
        cur = tmp->getNext();
    }
}

template<typename T>
Complex_listNode<T>* Pro26<T>::split()
{
    Complex_listNode<T>* copy_head = head->getNext();
    Complex_listNode<T>* copy_cur = copy_head;
    Complex_listNode<T>* head_cur = head;
    Complex_listNode<T>* cur = head->getNext()->getNext();//从第三个节点，即原表中的第二个几点开始分离
    bool flag = true;
    while(cur != NULL)
    {
        if(flag)//应该被加入head list
        {
            head_cur->setNext(cur);
            head_cur = cur;
            cur = cur->getNext();
            flag = !flag;
        }
        else
        {
            copy_cur->setNext(cur);
            copy_cur = cur;
            cur = cur->getNext();
            flag = !flag;
        }
    }
}
