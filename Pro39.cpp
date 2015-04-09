#include "Pro39.h"

int Pro39_2::getDepth(bnode<int> *root)
{
    if(root == NULL)
        return 0;
    int leftDep = getDepth(root->getLeft());
    int rightDep = getDepth(root->getRight());
    return leftDep > rightDep ? leftDep + 1 : rightDep + 1;
}

bool Pro39_2::isBalance(bnode<int> *root , int *pathLen)
{
    if(root == NULL)
    {
        *pathLen = 0;
        return true;
    }
    int leftLen , rightLen;
    bool leftBalance , rightBalance , rs = false;
    leftBalance = isBalance(root->getLeft() , &leftLen);
    rightBalance = isBalance(root->getRight() , &rightLen);
    *pathLen = leftLen > rightLen ? leftLen + 1 : rightLen + 1;
    if(leftLen - rightLen <= 1 && leftLen - rightLen >= -1)
        rs = true;
    return rs && leftBalance && rightBalance;
}
