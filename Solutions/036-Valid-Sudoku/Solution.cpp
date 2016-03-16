class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowValid[9], columnValid[9], subboxValid[9];
        
        // i : the i-th row of Sudoku
        // j : the j-th colum of Sudoku
        // board[i][j] : the number at position of i-th row and j-th column
        // i : 0-9, j : 0-9, k : 0-9
        // rowValid :  rowValid[k] == 1 if the k is exist at the current row(i-th row) 
        //              here, i : row, j : column
        // columnValid :  columnValid[k] == 1 if the k is exist at the current column(i-th column) 
        //              here, i : column, j : row
        // subboxValid :  subboxValid[k] == 1 if the k is exist at the current sub-box(i-th sub-box) 
        //              here, i : idx of sub-box, j : idx of number in this sub-box
        //              so, subbox[i][j] is the element at 3*(i/3)+j/3 row, 3*(i/3)+j%3 column 
        for(int i =0; i < 9; i++){
            memset(rowValid, 0, sizeof(rowValid));
            memset(columnValid, 0, sizeof(columnValid));
            memset(subboxValid, 0, sizeof(subboxValid));
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if( rowValid[board[i][j]-'1'] == 1 )
                        return false;
                    else 
                        rowValid[board[i][j]-'1'] = 1;
                }
               if(board[j][i] != '.'){
                    if( columnValid[board[j][i]-'1'] == 1 )
                        return false;
                    else 
                        columnValid[board[j][i]-'1'] = 1;
                }
                if(board[3*(i/3) + j/3][3*(i%3) + j%3]  != '.'){
                    if( subboxValid[board[3*(i/3) + j/3][3*(i%3) + j%3] - '1'] == 1 )
                        return false;
                    else 
                        subboxValid[board[3*(i/3) + j/3][3*(i%3) + j%3] - '1'] = 1 ;
                }
            }
        }
        return true;
    }
};
