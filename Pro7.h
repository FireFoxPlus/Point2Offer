//用两个栈实现队列
#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

#include <stack>
using namespace std;

template<typename T>
class Pro7
{
public :
    void appendTail(T tvalue);
    T deleteHead();
private :
    mstack<T> in;
    mstack<T> out;
};

template<typename T>
void Pro7<T>::appendTail(T tvalue)
{
    in.push(tvalue);
}

template<typename T>
T Pro7<T>::deleteHead()
{
    T rs;
    if(out.getLength() != 0)
        rs = out.pop();
    else if(in.getLength() != 0)
    {
        while(in.getLength() != 0)
            out.push(in.pop());
        rs = out.pop();
    }
    else
    {
        cout<<"╤сапн╙©у";
        return -1;
    }
    return rs;
}

class Pro7_2
{
public :
    Pro7_2()
    {
        sizes = 0;
    }
    void push(int);
    void pop() throw(int);
    int fronts()throw(int);
private :
    stack<int> in;
    stack<int> out;
    int sizes;
};
