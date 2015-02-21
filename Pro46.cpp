#include "Pro46.h"

int Pro46::sum = 0;
int Pro46::n = 0;

int terminal(int n)
{
    return 0;
}

int getSum(int n)
{
    return funcs[!!n](n - 1) + n;
}
