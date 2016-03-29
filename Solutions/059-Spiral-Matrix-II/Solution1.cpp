class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        
        int startRow = 0, startCol = 0;
        int endRow = n-1, endCol = n-1;

        int i;
        int cnt = 1;
        while(startRow <= endRow && startCol <= endCol){
            // first row
            for(i = startCol; i <= endCol; i++ )
                ret[startRow][i]=  cnt++;
            startRow++;
            // last column
            for(i = startRow; i <= endRow; i++)
                ret[i][endCol] = cnt++;
            endCol--;
            // last row
            if(startRow <= endRow ){
                for(i = endCol; i >= startCol; i--)
                    ret[endRow][i] = cnt++;
                endRow--;
            }
            // first column
            if(startCol <= endCol){
                for(i = endRow; i >= startRow; i--)
                    ret[i][startCol] = cnt++;
                startCol++;
            }
        }

        return ret;
    }
};
