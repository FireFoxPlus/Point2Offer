#include <iostream>
#include <cstring>
#include <memory>
#include "Pro27.h"

using namespace std;

int main()
{
    int values[] = {5 , 3 , 7 , 2 , 4 , 6 , 8};
    btree<int> tree(values , 7);
    Pro27 obp;
    bnode<int> *head = obp.getLeftMost(tree.getRoot());
    obp.tree2List(tree.getRoot());
    int counts = 0;
    while(counts < 7)
    {
        cout<<head->getValue();
        head = head->getRight();
        counts++;
    }

}
