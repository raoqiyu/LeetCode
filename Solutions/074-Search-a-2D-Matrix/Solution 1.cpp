class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        // Binary Search
        int m = matrix.size(), n = matrix[0].size();
        if(m == 0 || n == 0) return false;

        int row = 0, col = n-1;
        while(row < m && col > -1){
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target)
                // Search column position
                col--;
            else
                // Search row position
                row++;
        }
        return false;
    }
};
