class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Search from the top-right position
        // if target > matrix[i][j], then target cannot be exist in this row then i++
        // if target < matrix[i][j], then target cannot be exist in this column then j--
        int n_row = matrix.size();
        if(n_row == 0)
            return false;
        int n_col = matrix[0].size();
        if(n_col == 0)
            return false;
            
        int i = 0, j = n_col-1;
        while(i < n_row && j >= 0){
            if(target == matrix[i][j])
                return true;
            if(target > matrix[i][j])
                i++;
            else if(target < matrix[i][j])
                j--;

        }
        return false;
    }
};
