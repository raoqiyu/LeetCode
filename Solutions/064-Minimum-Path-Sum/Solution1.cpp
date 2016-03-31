class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //Dynamic Programming
        // Path[i][j] : a path from top left to grid[i][j] which has the minimum sum of all number along its path
        // Path[0][i] == Path[0][i-1]+grid[0][i] 
        // Path[..][0] == Path[i-1][0] + grid[i][0]
        // Path[i][j] = min(Path[i-1][j] + Path[i][j-1]) + grid[i][j]
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> Path(m, vector<int>(n));
        
        Path[0][0] = grid[0][0];
        for(int i = 1; i < m; i++)  Path[i][0] = Path[i-1][0] + grid[i][0];
        for(int i = 1; i < n; i++)  Path[0][i] = Path[0][i-1] + grid[0][i];
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++){
                Path[i][j] = min(Path[i-1][j],Path[i][j-1]) + grid[i][j];
            }
            
        int cnt = Path[m-1][n-1];
        return cnt;
    }
};
