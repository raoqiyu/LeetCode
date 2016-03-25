class Solution {
public:
    int totalNQueens(int n) {
        int *marked = new int[n];
        memset(marked, -1, sizeof(int)*n);

        N = n;
        nSolution = 0;
        solveNQueens(marked, 0);
        delete [] marked;
        return nSolution;

    }
private:
    int N;
    int nSolution;
    void solveNQueens(int *marked, int col)
    {
        if(col >= N){
            nSolution++;
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

};
