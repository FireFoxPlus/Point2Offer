#include "Pro22.h"
#include <stack>
using namespace std;
bool Pro22_2::isRightOrder(char *ori , char *pop)
{
    stack<char> help;
    for(int oriPace = 0 , popPace = 0;
        ori[oriPace] != '\0' && pop[popPace] != '\0'; )
    {
        help.push(ori[oriPace]);
        oriPace++;
        while(!help.empty() && help.top() == pop[popPace])
        {
            help.pop();
            popPace++;
        }
    }
    if(help.empty())
        return true;
    else
        return false;

}
