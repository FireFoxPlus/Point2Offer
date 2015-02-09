#include "Pro25.h"

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
