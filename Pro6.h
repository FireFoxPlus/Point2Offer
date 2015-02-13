#include "utils.h"
template<typename T>
class Pro6
{
public :
    Pro6(T *tpre , T * tmiddle , int tlength);
    bnode<T> * rebuild(T* startpre , T* endpre , T *startmid , T *endmid);
    int finds(T *values , T target);
    bnode<T> * getRoot()
    {
        return root;
    }
    void setRoot(bnode<T> *troot)
    {
        root = troot;
    }
    T* getPre()
    {
        return pre;
    }
    T* getMid()
    {
        return middle;
    }
private :
    T * pre;
    T * middle;
    int length;
    bnode<T> *root;
};

template<typename T>
Pro6<T>::Pro6(T *tpre , T * tmiddle , int tlength)、
{
    pre = tpre;
    middle = tmiddle;
    root = NULL;
    length = tlength;
}

template<typename T>
bnode<T> * Pro6<T>::rebuild(T* startpre , T* endpre , T* startmid , T* endmid)
{
        bnode<T> *root = new bnode<T>(startpre[0]);
        bnode<T> *left = NULL;
        bnode<T> *right = NULL;
        if(startpre == endpre || startmid == endmid)
            return root;
        int rs = finds(startmid , startpre[0]);
        if(rs > 0)//注意！什么时候才构建左子树
            left = rebuild(startpre + 1 , startpre + rs , startmid , startmid + rs - 1);
        if(rs + startmid != endmid)//注意！什么时候才构建右子树
            right = rebuild(startpre + rs + 1 , endpre , startmid + rs + 1 , endmid);
        root->setLeft(left);
        root->setRight(right);
        return root;
}

template<typename T>
int Pro6<T>::finds(T *values , T target)
{
    int n = 0;
    while(true)
    {
        if(values[n] == target)
            break;
        n++;
    }
    return n;
}
