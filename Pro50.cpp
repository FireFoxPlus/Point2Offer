#include "Pro50.h"

bnode<int> *Pro50::SortTreeFirstCommon(bnode<int> *root , bnode<int> *node1 , bnode<int> *node2)
{
    if(root == NULL)
        return NULL;
    while(root)
    {
        if(root->getValue() < node1->getValue() && root->getValue() < node2->getValue())
            root = root->getRight();
        else if(root->getValue() > node1->getValue() && root->getValue() > node2->getValue())
            root = root->getLeft();
        else if(root->getValue() > node1->getValue() && root->getValue() < node2->getValue())
            return root;
        else if(root->getValue() < node1->getValue() && root->getValue() > node2->getValue())
            return root;
    }
    return NULL;                                                                                                                                                                                                                                                                                                ;
}

bool Pro50::getPath(bnode<int> *root , bnode<int> *target , mstack<bnode<int> *> *path)
{
    if(root == target)
        return true;
    if(root == NULL)
        return false;
    path->push(root);
    bool rs = false;
    for(int i = 0; i < 2 && !rs; i++)
    {
        if(i == 0)
            rs = getPath(root->getLeft() , target , path);
        else
            rs = getPath(root->getRight() , target , path);
    }
    if(!rs)
        path->pop();
    return rs;
}

int Pro50::toInt(char *str)
{
    int sign = 1;
    int rs = 0;
    if(*str == '-')
    {
        sign = -1;
        str++;
    }
    while(*str != '\0')
    {
        rs = rs * 10 + *str - '0';
        str++;
    }
    return rs * sign;
}

bool Pro50::getPath(bnode<int> *root , bnode<int> *target ,
                    stack<bnode<int> *> &paths)
{
    if(root == NULL)
        return false;
    if(root == target)
    {
        paths.push(target);
        return true;
    }
    bool left , right;
    paths.push(root);
    left = getPath(root->getLeft() , target , paths);
    right = getPath(root->getRight() , target , paths);
    if(left || right)
        return true;
    else
        paths.pop();
    return false;
}

bnode<int> *Pro50::getFirstAnc(stack<bnode<int> *> &path1 , stack<bnode<int> *> &path2)
{




}
