class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        Solver(board);
    }
private:
    bool Solver(vector<vector<char>>& board)
    {
        int row, col;
        
        // find a unfilled position
        if(!findUnfilledPos(board, row, col))
            return true;
        // consider digits from 1 to 9
        for(int num = 1; num <= 9; num++){
            if(isSafe(board, row, col, num+'0')){
                board[row][col] = num+'0';
                if(Solver(board))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    bool findUnfilledPos(vector<vector<char>>& board, int &row, int &col)
    {
        // Search the board to find a position that is still unassigned.=.
        int i, j;
        for(i = 0; i < 9; i++)
            for(j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    row = i; col = j;
                    return true;
                }
            }
        return false;
    }
    bool isSafe(vector<vector<char>>& board, int &row, int &col, int num)
    {
        //Check if 'num' is not already placed in current row, current column and current 3x3 sub-board
        int startRow = row-row%3, startCol = col- col%3;
        for(int i = 0; i < 9; i++){
            // 1. current row
            if(board[row][i] == num)
                return false;
            // 2. current column
            if(board[i][col] == num)
                return false;
            // 3. current sub-board
            if(board[startRow + i/3][startCol + i%3] == num)
                    return false;
            
        }

        return true;
    }
};
