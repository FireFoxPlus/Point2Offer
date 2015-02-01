#include "utils.h"
template<typename T>
class Pro5{
public :
    Pro5(T *tvalue , int length);
    void dscPrint();
private :
    slist<T> values;
    mstack<T> help;
};

template<typename T>
Pro5<T>::Pro5(T *tvalue , int length){
    int i = 0;
    while(i < length){
        values.tailInsert(tvalue[i]);
        help.push(tvalue[i]);
        i++;
    }
}

template<typename T>
void Pro5<T>::dscPrint(){
      while(help.getLength() > 0){
        cout<<help.pop();
    }



}
