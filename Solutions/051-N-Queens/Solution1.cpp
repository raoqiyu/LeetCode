class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        int *marked = new int[n];
        memset(marked, -1, sizeof(int)*n);

        solutions.clear();
        N = n;
        solveNQueens(marked, 0);
        delete [] marked;
        return solutions;

    }
private:
    vector<vector<string>> solutions;
    int N;
    void solveNQueens(int *marked, int col)
    {
        if(col >= N){
            addSolution(marked);
            return ;
        }
        for(int i = 0; i < N; i++){
            if(isSafe(marked, col,i)){
                marked[col]= i;
                solveNQueens(marked, col+1);
                marked[col]= -1;
            }
        }
    }

    bool isSafe(int *marked, int col, int pos)
    {

        // Column conflict & row conflict
        for(int i = 0; i < col; i++)
            if(marked[i] == pos)
                return false;
        // Diagonal  conflict
        for(int i = 0; i < col; i++){
            if( abs(marked[i] - pos) == abs(col - i))
                return false;
        }

        return true;
    }

    void addSolution(int *marked)
    {
        vector<string> solution;
        for(int i = 0; i < N; i++){
            string row ;
            for(int j = 0; j < N; j++){
                    row += ".";
            }
            row[marked[i]] = 'Q';
          //  cout << row << endl;
            solution.push_back(row);
        }

        solutions.push_back(solution);
    }

};
