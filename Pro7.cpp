#include "Pro7.h"

int Pro7_2::fronts() throw(int)
{
    if(sizes == 0)
        throw -1;
    if(!out.empty())
        return out.top();
    while(!in.empty())
    {
        int tmp = in.top();
        out.push(tmp);
        in.pop();
    }
    return out.top();
}

void Pro7_2::pop() throw(int)
{
    if(sizes == 0)
        throw -1;
    if(!out.empty())
    {
        out.pop();
        sizes--;
        return;
    }

    while(!in.empty())
    {
        int tmp = in.top();
        out.push(tmp);
        in.pop();
    }
    out.pop();
    sizes--;
}

void Pro7_2::push(int v)
{
    in.push(v);
    sizes++;
}
