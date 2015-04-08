//二维数组中的查找
//在一个二维数组中，每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下的递增顺序排序，
//输入一个二维数组和一个值，判断其是否在二维数组中
template<int n>
class Pro3
{
public :
    Pro3(int tcols , int trows , int tvalue[][n]);
    bool mfind(int target);
private :
    int cols;
    int rows;
    int (*values)[n];
};

template<int n>
Pro3<n>::Pro3(int trows , int tcols , int tvalue[][n])
{
    cols = tcols;
    rows = trows;
    values = tvalue;
}

template<int n>
bool Pro3<n>::mfind(int target)
{
    int startcol = cols - 1, startrow = 0;
    while(startcol >= 0 && startrow < rows)
    {
        if(values[startrow][startcol] == target)
            return true;
        if(values[startrow][startcol] > target)
            startcol--;
        else if(values[startrow][startcol] < target)
            startrow++;
    }
    return false;
}

class Pro3_2
{
public :
    bool findInMatrix(int val[][] , int height , int width);
};
