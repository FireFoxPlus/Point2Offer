#include "Pro27.h"

bnode<int> *Pro27::getLeftMost(bnode<int> * root)
{
    if(root == NULL)
        return NULL;
    bnode<int> *tmp = root;
    while(tmp->getLeft() != NULL)
        tmp = tmp->getLeft();
    return tmp;
}

bnode<int> *Pro27::getRightMost(bnode<int> *root)
{
    if(root == NULL)
        return NULL;
    bnode<int> *tmp = root;
    while(tmp->getRight() != NULL)
        tmp = tmp->getRight();
    return tmp;
}

void Pro27::tree2List(bnode<int> *root)
{
    if(root->getLeft() != NULL)
    {
        bnode<int> *root_left = getRightMost(root->getLeft());
        tree2List(root->getLeft());
        root->setLeft(root_left);
        root_left->setRight(root);
    }
    else
        root->setLeft(NULL);

    if(root->getRight() != NULL)
    {
        bnode<int> *root_right = getLeftMost(root->getRight());
        tree2List(root->getRight());
        root->setRight(root_right);
        root_right->setLeft(root);
    }
    else
        root->setRight(NULL);

    if(root->getLeft() == NULL && root->getRight() == NULL)
        return;
}
