#include "utils.h"
template<typename T>
class Pro22
{
public :
    bool judge(T* oriseq , T* popseq , int length);
private :
    mstack<T> help;
};

template<typename T>
bool Pro22<T>::judge(T *oriseq , T * popseq , int length)
{
    bool rs;
    int oripace = 0;
    int poppace = 0;
    while(poppace < length)
    {
        if(help.getLength() == 0 && oripace < length)
        {
            help.push(oriseq[oripace]);
            oripace++;
        }
        if(help.top() == popseq[poppace])
        {
            help.pop();
            poppace++;
        }
        else
        {
            help.push(oriseq[oripace]);
            oripace++;
        }
        if(help.getLength() != 0 && help.top() != popseq[poppace] && oripace == length - 1)
        {
            rs = false;
            break;
        }
        if(oripace == length && help.getLength() == 0)
        {
            rs = true;
            break;
        }
    }
    return rs;
}
