//Pro49 把字符串转换为整数
//树中两个节点的最低公共祖先
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H
class Pro50
{
public :
    bnode<int> *SortTreeFirstCommon(bnode<int> *root , bnode<int> *node1 , bnode<int> *node2);
    bool getPath(bnode<int> *root , bnode<int> *target , mstack<bnode<int> *> *path);
} ;
