//二叉树的深度
//是否是平衡二叉树，即左右子树高度差不超过1
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

template<typename T>
class Pro39
{
public :
    Pro39()
    {
        maxLen = 0;
    }
    int getMaxLen()
    {
        return maxLen;
    }
    void longPath(bnode<T> *root , int pathLen);
    int longPath(bnode<T> *root);
    bool balanceTree(bnode<T> *root);
    bool balanceTree_2(bnode<T> *root , int *depth);
private :
    int maxLen;
};

template<typename T>
void Pro39<T>::longPath(bnode<T> *root , int pathLen)
{
    if(root == NULL)
        return;
    if(root->getLeft() == NULL && root->getRight() == NULL)
    {
        maxLen = maxLen > pathLen ? maxLen : pathLen;
        return;
    }
    if(root->getLeft() != NULL)
        longPath(root->getLeft() , pathLen + 1);
    if(root->getRight() != NULL)
        longPath(root->getRight() , pathLen + 1);
}

template<typename T>
int Pro39<T>::longPath(bnode<T> *root)
{
    if(root == NULL)
        return 0;
    int leftLen = longPath(root->getLeft());
    int rightLen = longPath(root->getRight());
    return leftLen > rightLen ? (leftLen + 1) : (rightLen + 1);
}

template<typename T>
bool Pro39<T>::balanceTree(bnode<T> *root)
{
    if(root == NULL)
        return true;
    int leftLen , rightLen;
    maxLen = 0;
    if(root->getLeft() != NULL)
        longPath(root->getLeft() , 0);
    leftLen = maxLen;
    if(root->getRight() != NULL)
    {
        maxLen = 0;
        longPath(root->getRight() , 0);
    }
    rightLen = maxLen;
    if(leftLen - rightLen > 1 || leftLen -  rightLen < -1)
        return false;
    else
        return balanceTree(root->getLeft()) && balanceTree(root->getRight());
}

template<typename T>
bool Pro39<T>::balanceTree_2(bnode<T> *root , int *depth)
{
    if(root == NULL)
    {
        *depth = 0;
        return true;
    }
    int leftDep , rightDep;
    if(balanceTree_2(root->getLeft() , &leftDep) && balanceTree_2(root->getRight() , &rightDep))
    {
        if(leftDep - rightDep <= 1 && leftDep - rightDep >= -1)
        {
            *depth = leftDep > rightDep ? (leftDep + 1) : (rightDep + 1);
            return true;
        }
    }
    return false;
}

class  Pro39_2
{
public :
    int getDepth(bnode<int> *root);
    bool isBalance(bnode<int> *root , int *longPath);
};

