#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;
void merges(int * vals , int start , int mid , int high);
void mergeSort(int* vals , int low , int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(vals , low , mid);
        mergeSort(vals , mid + 1 , high);
        merges(vals , low , mid , high);
    }
}

void merges(int * vals , int start , int mid , int high)
{
    int* help = new int[high - start + 1];
    memcpy(help , vals + start , sizeof(int) * (high - start + 1));
    for(int i = 0; i < high - start +1; i++)
        cout<<help[i]<<" ";
    cout<<endl;
    int firStart = start;
    int secStart = mid + 1;
    int counts = start;
    while(firStart < mid + 1 && secStart <= high)
    {
        if(help[firStart - start] < help[secStart - start])
        {
            vals[counts] = help[firStart - start];
            counts++;
            firStart++;
        }
        else
        {
            vals[counts] = help[secStart - start];
            counts++;
            secStart++;
        }
    }
    while(firStart < mid + 1)
    {
        vals[counts] = help[firStart - start];
        firStart++;
        counts++;
    }
}
