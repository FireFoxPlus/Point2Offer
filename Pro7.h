//用两个栈实现队列
#include "utils.h"
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
