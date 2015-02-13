bool isOdd(int value);

class Pro14
{
public :
    typedef bool (*Judge)(int);
    void swapOdd(int *values , int length , Judge judge);
};
