class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        self.board = board;
        # flag : to indicate whether we have met a solution
        self.flag = False
        # record the values thar are alreadly exist i the sudoku
        # row : value in each row; col : value in  rach column; sub : value in each sub-sudoku
        self.rowExist =  [[False]*10 for i in range(9)]
        self.colExist  = [[False]*10 for i in range(9)]
        self.subExist  = [[False]*10 for i in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                num = int(board[i][j])
                sub_idx = (i/3)*3 + j/3
                self.rowExist[i][num] = self.colExist [j][num] = self.subExist[sub_idx][num] = True
                
        self.backtracking(0, 0)
        
    def backtracking(self,row, col):
        # bound 
        if self.flag :
            return
        if row > 8:
            self.flag  = True
            return
        
        # branch
        if self.board[row][col] != '.':
            if col < 8:
                self.backtracking(row,col+1)
            else:  
                self.backtracking(row+1,0)
            if self.flag:
                return
        else:
            # enumerate every possible solution
            sub_idx = row/3*3 + col/3
            for num in range(1,10):
                # if this number is valid
                if not self.rowExist[row][num] and not self.colExist[col][num] and not self.subExist[sub_idx][num]:
                    self.board[row][col] = str(num)
                    self.rowExist[row][num] = self.colExist[col][num] = self.subExist[sub_idx][num] = True
                    
                    if col < 8:
                        self.backtracking(row,col+1)
                    else:
                        self.backtracking(row+1,0)
          
                    if self.flag :
                        return
          
                    self.rowExist[row][num] = self.colExist[col][num] = self.subExist[sub_idx][num] = False
            self.board[row][col] = '.'

            
