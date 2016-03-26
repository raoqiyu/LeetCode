class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        
        int m = matrix.size();
        if(m == 0) return  ret;
        
        int n = matrix[0].size();
        int startRow = 0, startCol = 0;
        int endRow = m-1, endCol = n-1;

        int i;
        while(startRow <= endRow && startCol <= endCol){
            // first row
            for(i = startCol; i <= endCol; i++ )
                ret.push_back(matrix[startRow][i]);
            startRow++;
            // last column
            for(i = startRow; i <= endRow; i++)
                ret.push_back(matrix[i][endCol]);
            endCol--;
            // last row
            if(startRow <= endRow ){
                for(i = endCol; i >= startCol; i--)
                    ret.push_back(matrix[endRow][i]);
                endRow--;
            }
            // first column
            if(startCol <= endCol){
                for(i = endRow; i >= startRow; i--)
                    ret.push_back(matrix[i][startCol]);
                startCol++;
            }
        }

        return ret;
    }
};
