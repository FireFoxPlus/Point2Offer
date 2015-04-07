#include <iostream>
#include <cstring>
#include <memory>
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H
#include "Pro47.h"
#include "Pro11.h"
#include "Pro12.h"
#include "Pro14.h"
#include "Pro17.h"
#include "Pro18.h"
#include <vector>

using namespace std;

int main()
{
  Pro18<int> ob;
  int val[] = {1 , 2 , 3 , 4 , 5};
  int val2[] = {2 , 4 , 6};
  btree<int> a(val , 5);
  btree<int> b(val2 , 3);
  if(ob.isSubTree(a.getRoot() , b.getRoot()))
    cout<<"subTree";
}
