#include "Pro21.h"

int Pro21_2::top()
{
    return value.top();
}

void Pro21_2::push(int val)
{
    value.push(val);
    if(mins.top() > val || mins.empty())
        mins.push(val);
}

int Pro21_2::pop()
{
    int rs = value.top();
    value.pop();
    if(mins.top() == rs)
        mins.pop();
    return rs;
}

int Pro21_2::getMin()
{
    return mins.top();
}
