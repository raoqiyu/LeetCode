class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        // Binary Search
        int m = matrix.size(), n = matrix[0].size();
        if(m == 0 || n == 0) return false;
        
        // First, search a row which contain target
        int top = 0, bottom = m-1;
        while(top <= bottom){
            int mid = (top+bottom)/2;
            if(matrix[mid][0] < target)
                top = mid+1;
            else if(matrix[mid][0] > target)
                bottom = mid-1;
            else
                return true;
        }
        // Search column position at row bottom
        if(bottom != -1){
            int left = 0, right = n-1;
            while(left <= right){
                int mid = (left+right)/2;
                if(matrix[bottom][mid] < target)
                    left = mid+1;
                else if(matrix[bottom][mid] > target)
                    right = mid-1;
                else
                    return true;
            }
        }
        return false;
    }
};
