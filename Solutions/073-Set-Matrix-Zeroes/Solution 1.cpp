class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // use first row and first column to do make mark
        // matrix[i][0] == 0 means that the i-th row will be set zeroes
        // matrix[0][j] == 0 means that the j-th column will be set zeroes
        // leave the first row when set zeroes, because if set first row zeroes we lost the mark information about the column which should be set zeroes
        // And this operation will not break the origin information of the first row and first column
        int m = matrix.size(), n = matrix[0].size();
        // keep the origin information of first row
        bool f = false;
        for(int i = 0; i < n; i++)
            if(matrix[0][i] == 0){
                f = true;
                break;
            }
        // Make mark
        for(int i = 1; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        
        // Set Matrix Zeroes
        // Set row (leave the first row)
        for(int i = 1; i < m; i++)
            if(matrix[i][0] == 0)
                for(int k = 1; k < n; k++)
                    matrix[i][k] = 0;
        // Set column
        for(int j = 0; j < n; j++)
            if(matrix[0][j] == 0)
                for(int k = 1; k < m; k++)
                    matrix[k][j] = 0;
        // Check the first row with its origin information
        if(f)
            for(int i = 0; i < n; i++)
                matrix[0][i] = 0;
        return ;
    }
    
};
