#include "preInclude.h"
using namespace std;

void merges(int * vals , int start , int mid , int high);
void mergeSort(int* vals , int low , int high);
int main()
{
    int vals[] = {2 , 6 , 8 , 3 , 1 ,9 };
    mergeSort(vals , 0 , 5);
    for(int i = 0; i < 6; i++)
        cout<<vals[i]<<" ";
}
