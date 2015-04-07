//二叉树的镜像
//输入二叉树，输出该二叉树的镜像
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

template<typename T>
class Pro19
{
public :
    void mirrorTree(bnode<T> *root);
};

template<typename T>
void Pro19<T>::mirrorTree(bnode<T> *root)
{
    if(root == NULL)
        return;
    bnode<T>* tmp = root->getLeft();
    root->setLeft(root->getRight());
    root->setRight(tmp);
    mirrorTree(root->getLeft());
    mirrorTree(root->getRight());
}
