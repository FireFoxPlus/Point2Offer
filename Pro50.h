//Pro49 把字符串转换为整数
//树中两个节点的最低公共祖先
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

#include <stack>
using namespace std;

class Pro50
{
public :
    bnode<int> *SortTreeFirstCommon(bnode<int> *root , bnode<int> *node1 , bnode<int> *node2);
    bool getPath(bnode<int> *root , bnode<int> *target , mstack<bnode<int> *> *path);
    int toInt(char *str);
    bool getPath(bnode<int> *root , bnode<int> *target , stack<bnode<int> *> &path);
    bnode<int>* getFirstAnc(stack<bnode<int> *> &path1 , stack<bnode<int>*> &path2);
} ;
