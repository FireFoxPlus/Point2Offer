#include "utils.h"
template<typename T>
class Pro23
{
public :
    void BFSTree(bnode<T> *root);
private :
    mqueue<bnode<T> *> cache;
};

template<typename T>
void Pro23<T>::BFSTree(bnode<T> *root)
{
    if(root == NULL)
        return;
    cache.addQueue(root);
    bnode<T> *temp;
    while(cache.getLength() != 0)
    {
        temp = cache.deQueue();
        cout<<temp->getValue();
        if(temp->getLeft() != NULL)
            cache.addQueue(temp->getLeft());
        if(temp->getRight() != NULL)
            cache.addQueue(temp->getRight());
    }
}
