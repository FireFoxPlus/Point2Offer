bool Compare(int val1 , int val2);
void tailCopy(char*rs , int val);

class Pro33
{
public :
    Pro33()
    {
        mins = 0x08000000;
    }
    void getMinInArray(int *values , int length , int cur , char *rs);
    char *appendChar(char *rs , int val);
    int getMins()
    {
        return mins;
    }
    void getMinsInArray_2(int *values , int length);
    friend bool Compare(int val1 , int val2);
    friend void tailCopy(char*rs , int val);
private :
    int mins;
};

