class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //Dynamic Programming
        int nRows = triangle.size();
        if(nRows < 1) return 0;
        
        // from bottom to top
        for(int i = nRows-2; i >= 0; i--){
            for(int j = 0; j <=i; j++)
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        }
        
        return triangle[0][0];
        
    }
};
