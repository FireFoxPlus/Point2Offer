//包含min函数的栈
//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数
#include "utils.h"
template<typename T>
class Pro21
{
public :
    void push(const T& value);
    T& pop();
    T mins();

private:
    mstack<T> values;
    mstack<T> minvalue;
};

template<typename T>
void Pro21<T>::push(const T &value)
{
    values.push(value);
    if(minvalue.getLength() == 0)
        minvalue.push(value);
    else if(minvalue.top() > value)
        minvalue.push(value);
}

template<typename T>
T& Pro21<T>::pop()
{
    T rs;
    if(values.getLength() > 0)
    {
        if(minvalue.top() == values.top())
            minvalue.pop();
        rs = values.pop();
    }
    return rs;
}

template<typename T>
T Pro21<T>::mins()
{
    return minvalue.top();
}
