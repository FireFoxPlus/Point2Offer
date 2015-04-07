//二叉树中和为某一值的路径
//题目：输入一棵二叉树和一个整数，
//打印出二叉树中节点值的和为输入整数的所有路径，
//从树的根节点到叶结点所经过的节点形成一条路径
#include "utils.h"
class Pro25
{
public :
    void PrintSumPath(bnode<int> *root , int sum);
    void printPath(bnode<int> *root , int sum);
private :
    mstack<int> print_stack;
};
