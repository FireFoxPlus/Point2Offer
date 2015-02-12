#include <iostream>
#include <cstring>
#include <memory>
#include "Pro28.h"

using namespace std;

int main()
{
    char *val = "zhang";
    Pro28 obp(val);
    char *str = obp.getValue();
    obp.Allout(str);

}
