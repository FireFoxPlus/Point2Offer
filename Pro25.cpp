#include "Pro25.h"
using namespace std;
void Pro25::PrintSumPath(bnode<int> *root , int sum)
{
    bnode<int> *visits[100];//访问数组
    bool flag[100];//标志数组
    int now_sum = 0;
    int cur = 0;

    if(root != NULL)
    {
        visits[cur] = root;
        flag[cur] = 0;//未被访问过
    }
    bnode<int> *tmp;
    while(cur >= 0)
    {
        tmp = visits[cur];
        if(flag[cur] == 0)
        {
            now_sum += tmp->getValue();
            flag[cur] = 1;
            if(tmp->getLeft() != NULL)
            {
                cur++;
                visits[cur] = tmp->getLeft();
                flag[cur] = 0;
            }

            if(tmp->getRight() != NULL)
            {
                cur++;
                visits[cur] = tmp->getRight();
                flag[cur] = 0;
            }

            if(now_sum == sum)
            {
                print_stack.push(tmp->getValue());
                print_stack.print();
            }
            else
                print_stack.push(tmp->getValue());
        }
        else
        {
            now_sum -= tmp->getValue();
            print_stack.pop();
            cur--;
        }
    }
}

void Pro25::printPath(bnode<int> *root , int sum , stack<bnode<int>*> &paths)
{
    if(root == NULL)
        return;
    if(root->getValue() == sum)
        printSTLStack(paths);
    paths.push(root);
    printPath(root->getLeft() , sum - root->getValue() , paths);
    printPath(root->getRight() , sum - root->getValue() , paths);
    paths.pop();
}

void Pro25::printPath(bnode<int> *root , int sum)
{
    if(root == NULL)
        return;
    stack<bnode<int>*> paths;
    paths.push(root);
    printPath(root->getLeft() , sum - root->getValue() , paths);
    printPath(root->getRight() , sum - root->getValue() , paths);
    paths.pop();
}
void printSTLStack(stack<bnode<int>*> &paths)
{
    stack<bnode<int>*> help;
    while(!paths.empty())
    {
        bnode<int> *tmp = paths.top();
        cout<<tmp->getValue()<<" ";
        help.push(tmp);
        paths.pop();
    }
    cout<<endl;

    while(!help.empty())
    {
        bnode<int>* tmp = help.top();
        paths.push(tmp);
        help.pop();
    }
}
