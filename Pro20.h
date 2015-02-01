#include<iostream>
using namespace std;
template<int n>
class Pro20{
public :
    Pro20(int (*p)[n]){
        Uheight = 0;
        Dheight = n - 1;
        Lwidth = 0;
        Rwidth = n - 1;
        value = p;
    }
    void output();
private :
    int (*value)[n];
    int Uheight , Dheight;
    int Lwidth , Rwidth;
};

template<int n>
void Pro20<n>::output(){
    int counts = 0;
    int CH = 0, CW = 0;
    while(counts < n * n){
        //右
        for(CW = Lwidth; CW <= Rwidth ; CW++){
            cout<<value[CH][CW]<<' ';
            counts++;
            }
        CW -= 1;
        Uheight++;

        //下
        for(CH = Uheight; CH <= Dheight; CH++){
            cout<<value[CH][CW]<<' ';
            counts++;
        }
        CH -= 1;
        Rwidth--;

        //左
        for(CW = Rwidth; CW >= Lwidth; CW--){
            cout<<value[CH][CW]<<' ';
            counts++;
        }
        CW += 1;
        Dheight--;

        //上
        for(CH = Dheight; CH >= Uheight; CH--){
            cout<<value[CH][CW]<<' ';
            counts++;
        }
        CH += 1;
        Lwidth++;
        }
}
