#include "fastSort.h"
#include <iostream>

int partion(int *values , int length){
    if(values == NULL || length <=0)
        return -1;

    int flag = values[length - 1];
    int head = 0 , tail = length - 2;
    while(head <= tail){
        if(head == tail && tail != length - 2){
            int tmp = values[head];
            values[head] = flag;
            values[length - 1] = tmp;
            head++;
            continue;
        }
        else if(head == tail && tail == length - 2){
            head++;
            continue;
        }

        if(values[head] < flag){
            head++;
            continue;
        }
        else if(values[head] > flag){
            if(values[tail] > flag){
                tail--;
                continue;
            }
            else{
                int tmp = values[tail];
                values[tail] = values[head];
                values[head] = tmp;
                head++;
            }
        }
    }
    return head;
}


void fastSort(int *values , int length){
    if(length == 1)
        return;
    if(length == 2){
        int tmp = values[0];
        values[0] = values[0] < values[1] ? values[0] : values[1];
        values[1] = tmp > values[1] ? tmp : values[1];
        return;
    }

    int split = partion(values , length);

    if(split > 0)
        fastSort(values , split);
    if(split + 1 < length)
        fastSort(values + split + 1 , length - split -1);






}
