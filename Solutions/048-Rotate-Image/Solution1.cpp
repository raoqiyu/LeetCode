class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // rotate image : m'[i][j] = m[n-j-1][i]
        //
        //  1   2       4   2       3   1
        //  3   4       3   1       4   2
        //
        //
        // In-place
        int n = matrix.size();
        int layer = n/2;
        for(int i = 0; i < layer; i++)
            for(int j = i; j < n-i-1; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                //matrix[j][n-i-1] = matrix[i][j];
                matrix[j][n-i-1] = temp;
            }
    }
};
