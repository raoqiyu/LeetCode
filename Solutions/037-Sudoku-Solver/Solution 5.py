class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        # Backtracking: cache possible values for each position and update that after we choose a value each time
        self.board = board
        self.possible_values = self.findPossibleValues()
        self.backtracking()
        
    def backtracking(self):
        #bound
        if not self.possible_values:
            return True
        
        #choose next position which has the smallest numbet of possible values
        pos = min(self.possible_values.keys(), key=lambda x : len(self.possible_values[x]))
        #fetch this possible values
        nums = self.possible_values[pos]

        # enumerate every possible value
        for num in nums:
            # record the pos and value
            update = {pos:nums}
            # check if the num is calid
            if self.isValid(pos, num, update):
                # if valid , go to next position
                if self.backtracking():
                    return True
            #undo the choose and do another possible choose
            self.undo(pos, update)
        return False
            
        
    def isValid(self, pos, num, update):
        # fill this number 
        self.board[pos[0]][pos[1]] = num
        # delete all possible for this position
        del self.possible_values[pos]
        # update possible value for other position and check if this num is valid
        row, col = pos
        for idx in self.possible_values.keys():
            if num in self.possible_values[idx]:
                # update the infomation for the pos position(same row, same col, same sub part)
                if idx[0] == row or idx[1] == col or (row//3,col//3) == (idx[0]//3,idx[1]//3):
                    # record the infomation
                    update[idx] = num
                    # remove num from that position
                    self.possible_values[idx].remove(num)
                    # if there exist a position which has no possible values, then this num is a bad choice
                    if not self.possible_values[idx] :
                        return False;
        return True
                    
    def undo(self, pos, update):
        self.board[pos[0]][pos[1]] = '.'
        for k in update:
            if k not in self.possible_values:
                self.possible_values[k] = update[k]
            else:
                self.possible_values[k].append(update[k])
        
        
    def findPossibleValues(self):
        nums = '123456789'
        exist, not_exist = {}, {}
        for i in range(9):
            for j in range(9):
                num = self.board[i][j]
   
                if num != '.':
                    exist[('r',i)] = exist.get(('r',i),[]) + [num]
                    exist[('c',j)] = exist.get(('c',j),[]) + [num]
                    exist[(i//3,j//3)] = exist.get((i//3,j//3),[]) + [num]
                else:
                    not_exist[(i,j)] =[]
                    
                    
        for (i,j) in not_exist.keys():
            exist_values = exist.get(('r',i),[]) + exist.get(('c',j),[])+exist.get((i//3,j//3),[])
            not_exist[(i,j)] = [num for num in nums if num not in exist_values]
        
        return not_exist
        
       

            
