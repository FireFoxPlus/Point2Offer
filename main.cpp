#include <iostream>
#include <cstring>
#include <memory>
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H
#include "Pro39.h"

using namespace std;

int main()
{
    int a[] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8};
    int b[] = {1 , 2 , 3 , 4 , 5 , 6 , 7};
    btree<int> tree(a , 8);
    bnode<int> newNode;
    newNode.setValue(9);
  //  tree.getRoot()->getLeft()->getLeft()->getLeft()->setLeft(&newNode);
    Pro39<int> obp;
    int depth = 0;
    if(obp.balanceTree_2(tree.getRoot() , &depth))
        cout<<"balance tree";
    else
        cout<<"imbalance";

}
