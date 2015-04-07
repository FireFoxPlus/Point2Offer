//顺时针打印矩阵
//题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印每一个数字
#include<iostream>
using namespace std;
template<int n>
class Pro20
{
public :
    Pro20()
    {}
    Pro20(int (*p)[n])
    {
        Uheight = 0;
        Dheight = n - 1;
        Lwidth = 0;
        Rwidth = n - 1;
        value = p;
    }
    void output();
    void printMatrix(int (*matrix)[n] , int height , int width);
private :
    int (*value)[n];
    int Uheight , Dheight;
    int Lwidth , Rwidth;
};

template<int n>
void Pro20<n>::output()
{
    int counts = 0;
    int CH = 0, CW = 0;
    while(counts < n * n)
    {
        //右
        for(CW = Lwidth; CW <= Rwidth ; CW++)
        {
            cout<<value[CH][CW]<<' ';
            counts++;
        }
        CW -= 1;
        Uheight++;

        //下
        for(CH = Uheight; CH <= Dheight; CH++)
        {
            cout<<value[CH][CW]<<' ';
            counts++;
        }
        CH -= 1;
        Rwidth--;

        //左
        for(CW = Rwidth; CW >= Lwidth; CW--)
        {
            cout<<value[CH][CW]<<' ';
            counts++;
        }
        CW += 1;
        Dheight--;

        //上
        for(CH = Dheight; CH >= Uheight; CH--)
        {
            cout<<value[CH][CW]<<' ';
            counts++;
        }
        CH += 1;
        Lwidth++;
    }
}

template<int n>
void Pro20<n>::printMatrix(int (*matrix)[n] , int height , int width)
{
    int upLine = 0 , downLine = height - 1,
        leftCol = 0 , rightCol = width - 1;
    for(int j = 0; j < height *  width;)
    {
        if(upLine == downLine && leftCol == rightCol)
        {
            cout<<matrix[upLine][rightCol]<<" ";
            j++;
        }
        for(int i = leftCol; i < rightCol; i++)
        {
            cout<<matrix[upLine][i]<<" ";
            j++;
        }

        for(int i = upLine; i < downLine; i++)
        {
            cout<<matrix[i][rightCol]<<" ";
            j++;
        }
        for(int i = rightCol; i > leftCol; i--)
        {
            cout<<matrix[downLine][i]<<" ";
            j++;
        }

        for(int i = downLine; i > upLine; i--)
        {
            cout<<matrix[i][leftCol]<<" ";
            j++;
        }
        upLine++;
        downLine--;
        leftCol++;
        rightCol--;
    }
}
