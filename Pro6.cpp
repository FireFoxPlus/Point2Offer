#include "Pro6.h"

bnode<int>* Pro6_2::rebuildBTree(char *preS , char *preE ,  char *midS , char *midE)
{
    //递归出口
    if(preS > preE || midS > midE || !preS || !preE || !midS ||!midE)
        return NULL;
    bnode<int> *root = new bnode<int>();
    root->setValue(*preS - '0');
    int midR = findRootInMid(*preS , midS);
    root->setLeft(rebuildBTree(preS + 1 , preS + midR ,
                               midS , midS + midR - 1));
    root->setRight(rebuildBTree(preS + midR + 1 , preE ,
                                midS + midR + 1 , midE));
    return root;
}

int Pro6_2::findRootInMid(char root , char *mid)
{
    int i;
    for(i = 0; mid[i] != '\0'; i++)
        if(mid[i] == root)
            break;
    return i;
}
