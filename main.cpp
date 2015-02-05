#include <iostream>
#include <cstring>
#include <memory>
#include "Pro25.h"
using namespace std;

int main()
{
    Pro25 obp;
    int values1[] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};
    btree<int> tree(values1 , 9);
    bnode<int>* root = tree.getRoot();
    obp.PrintSumPath(root , 3);
}
