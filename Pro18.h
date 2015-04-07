//树的子结构
//题目：输入两颗二叉树A和B，判断B是不是A的子结构
#include <queue>

#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

using namespace std;

template<typename T>
class Pro18
{
public :
    bool BFS(bnode<T>* froot , bnode<T>* croot);
    bool isChild(bnode<T> *froot , bnode<T>* croot);
    bool isSubTree(bnode<T> *foot , bnode<T>* croot);
    bool isSub(bnode<T> *froot , bnode<T> *croot);
};

template<typename T>
bool Pro18<T>::BFS(bnode<T>* froot , bnode<T>* croot)
{
    bool left , right , rs = false;
    //cout<<froot->getValue()<<"!!"<<endl;
    mqueue<bnode<T>* > que;
    if(froot != NULL)
        que.addQueue(froot);

    bnode<T>* tmp = NULL;
    while(que.getLength() != 0)
    {
        tmp = que.deQueue();
        if(tmp->getLeft() != NULL)
            que.addQueue(tmp->getLeft());
        if(tmp->getRight() != NULL)
            que.addQueue(tmp->getRight());

        if(tmp->getValue() == croot->getValue())
        {
            left = isChild(tmp->getLeft() , croot->getLeft());
            right = isChild(tmp->getRight() , croot->getRight());
            rs = left && right;
        }
        else
            rs = false;

        if(rs)
            break;
    }
    return rs;
}
template<typename T>
bool Pro18<T>::isChild(bnode<T> *froot , bnode<T>* croot)
{
    if(croot == NULL)
        return true;

    if(froot == NULL && croot != NULL)
        return false;

    if(froot->getValue() == croot->getValue())
        return isChild(froot->getLeft() , croot->getLeft()) && isChild(froot->getRight() , croot->getRight());
    else
        return false;
}

template<typename T>
bool Pro18<T>::isSubTree(bnode<T>* froot , bnode<T>* croot)
{
    bool rs = false;
    queue<bnode<T>* > que;
    if(froot != NULL)
        que.push(froot);
    else
        return false;
    while(!que.empty())
    {
        bnode<T> *tmp = que.front();
        que.pop();
        if(tmp->getLeft() != NULL)
            que.push(tmp->getLeft());
        if(tmp->getRight() != NULL)
            que.push(tmp->getRight());
        if(isSub(tmp , croot))
        {
            rs = true;
            break;
        }
    }
    return rs;
}

template<typename T>
bool Pro18<T>::isSub(bnode<T> *froot , bnode<T> *croot)
{
    if(croot == NULL)
        return true;
    if(froot == NULL)
        return false;
    if(froot->getValue() != croot->getValue())
        return false;
    else
        return isSub(froot->getLeft() , croot->getLeft())
        && isSub(froot->getRight() , croot->getRight());
}
