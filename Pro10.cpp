#include "Pro10.h"

//�˰汾�Ĳ������ڣ����numΪ�����������ѭ��
int Pro10::numOfOne(int num){
        int rs = 0;
        while(num != 0){
            if(num & 1)
                rs++;
            num >>= 1;
        }
        return rs;

}
//�Ľ��棬�ƶ�1������ԭ����
int Pro10::numOfOne2(int num){
    int rs = 0;
    int i = 1;
    while(i){
        if(num & i)
            rs++;
        i <<= 1;
    }
    return rs;
}
//�ٸĽ�������ԭ�� a&(a-1)����ȥa���Ҷ˵�1
int Pro10::numOfOne3(int num){
    int rs = 0;
    while(num){
        num &= num - 1;
        rs++;
    }
    return rs;

}
