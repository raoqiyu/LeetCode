class Solution(object):
    def solveNQueens(self, n):
        """
        Backtracking
        
        :type n: int
        :rtype: List[List[str]]
        """
        n_d = 2*n-1
        ret = []
        marked_x, marked_d1, marked_d2 = [False]*n,[False]*n_d,[False]*n_d
        solution = [-1]*n
        
        # fill a row. each time, y means that at the y-th row 
        def backtracking(y):
            # bound 
            if y == n:
                addSolution(solution)
                return
            
            # branch
            for x in range(n):
                d1, d2 = (y+x)%n_d, (y-x+n_d)%n_d
                # check conflict
                if not marked_x[x] and not marked_d1[d1] and not marked_d2[d2]:
                    # this position occupy 4 line(row, col and two diagonal line)
                    marked_x[x] = marked_d1[d1] = marked_d2[d2] = True
                    
                    solution[y] = x
                    backtracking(y+1)
                    
                    # restore
                    marked_x[x] = marked_d1[d1] = marked_d2[d2] = False
        
        # add one possible solution from a marked solution
        def addSolution(solution):
            sol = []
            for y in range(n):
                row  = ''
                for x_idx in range(n):
                    if x_idx != solution[y]:
                        row += '.'
                    else:
                        row += 'Q'
                sol.append(row)
            ret.append(sol)
                
        backtracking(0)
        
            
        return ret
        
