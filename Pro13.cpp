#include "Pro13.h"

int Pro13::delO1(snode<int> *head , snode<int> *del){
    int rs;
    snode<int> *next , *next_next;
    next = del->getNext();
    next_next = next->getNext();
    rs = del->getValue();
    del->setValue(rs);
    //del->setValue(next->getValue());
    del->setNext(next_next);
    delete next;
    return rs;
}

