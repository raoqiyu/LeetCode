class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //Dynamic Programming
        // Path[i][j] : number of unique paths to reach pos[i][j]
        // Path[0][..] == 1
        // Path[..][0] == 1
        // Path[i][j] = Path[i-1][j] + Path[i][j-1]
        // obstacle case : if obstacleGrid[i][j] == 1, then Path[i][j] = 0
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> Path(m, vector<int>(n));
        Path[0][0] = (obstacleGrid[0][0] == 0) ? 1:0;
        for(int i = 1; i < m; i++)
            Path[i][0] = (obstacleGrid[i][0] == 0) ? Path[i-1][0]:0;
        for(int i = 1; i < n; i++)
            Path[0][i] = (obstacleGrid[0][i] == 0) ? Path[0][i-1]:0;
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++){
                Path[i][j] = (obstacleGrid[i][j] == 0) ?  (Path[i-1][j] + Path[i][j-1]):0;
            }
            
        int cnt = Path[m-1][n-1];
        return cnt;  
    }
};
