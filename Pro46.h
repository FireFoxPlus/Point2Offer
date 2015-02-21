class Pro46;
static Pro46 *arrays[2];

typedef int (*fp)(int);

int terminal(int n);
int getSum(int n);

static fp funcs[2] = {terminal , getSum};

class Pro46
{
public :
    Pro46()
    {
        n++;
        sum += n;
    }
    virtual int getSum(int n)
    {
        return 0;
    }

    static int getSum()
    {
        return sum;
    }
private :
    static int sum;
    static int n;
};

class Pro46_2 : public Pro46
{
public :
    virtual int getSum(int n)
    {
        return arrays[!!n]->getSum(n - 1) + n;
    }
};
