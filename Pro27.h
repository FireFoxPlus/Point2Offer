#include "utils.h"
class Pro27{
public :
    bnode<int> *getLeftMost(bnode<int> *root);
    bnode<int> *getRightMost(bnode<int> *root);
    void tree2List(bnode<int> *root);
    void tree2List2(bnode<int> *root);
    void ConvertNode(bnode<int>* root , bnode<int>** LastInList);
};

