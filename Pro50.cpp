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
