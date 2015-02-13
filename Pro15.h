#include "utils.h"
template<typename T>
class Pro15
{
public :
    Pro15();
    void add(T value);
    T lastM(int M);
private :
    slist<T> mlist;
    int length;
};

template<typename T>
Pro15<T>::Pro15()
{
    length  = 0;
}

template<typename T>
void Pro15<T>::add(T value)
{
    mlist.tailInsert(value);
    length++;
}

template<typename T>
T Pro15<T>::lastM(int m)
{
    if(mlist.getHead() == NULL)
        ;
    if(length < m)
        ;
    snode<T> *firs;
    snode<T> *seco = mlist.getHead();
    for(int i = 0; i < m; i++)
    {
        if(i == 0)
            firs  = mlist.getHead();
        else
            firs = firs->getNext();
    }
    while(firs->getNext() != NULL)
    {
        firs = firs->getNext();
        seco = seco->getNext();
    }
    return seco->getValue();
}
