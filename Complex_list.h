template<typename T>
class Complex_listNode{
public :
    Complex_listNode()
    {
        next = NULL;
        sibling = NULL;
    }

    T getValue()
    {
        return value;
    }

    Complex_listNode<T>* getNext()
    {
        return next;
    }

    Complex_listNode<T>* getSibling()
    {
        return sibling;
    }

    void setValue(T values)
    {
        value = values;
    }

    void setNext(Complex_listNode<T> *next_)
    {
        next = next_;
    }

    void setSibling(Complex_listNode<T> *sibling_)
    {
        sibling = sibling_;
    }
private :
    T value;
    Complex_listNode<T> *next;
    Complex_listNode<T> *sibling;
};
