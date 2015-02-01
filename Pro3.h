template<int n>
class Pro3{
public :
    Pro3(int tcols , int trows , int tvalue[][n]);
    bool mfind(int target);
private :
    int cols;
    int rows;
    int (*values)[n];
};


template<int n>
Pro3<n>::Pro3(int trows , int tcols , int tvalue[][n]){
    cols = tcols;
    rows = trows;
    values = tvalue;
    }

template<int n>
bool Pro3<n>::mfind(int target){
    int startcol = cols - 1, startrow = 0;
    while(startcol >= 0 && startrow < rows){
        if(values[startrow][startcol] == target){
                return true;
        }
        if(values[startrow][startcol] > target)
            startcol--;
        else if(values[startrow][startcol] < target)
            startrow++;
    }
    return false;
    }

