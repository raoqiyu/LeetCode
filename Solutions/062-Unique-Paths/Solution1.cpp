class Solution {
public:
    int uniquePaths(int m, int n) {
        //Dynamic Programming
        // Path[i][j] : number of unique paths to reach pos[i][j]
        // Path[0][..] == 1
        // Path[..][0] == 1
        // Path[i][j] = Path[i-1][j] + Path[i][j-1]
        
        vector<vector<int>> Path(m, vector<int>(n));
        
        for(int i = 0; i < m; i++)  Path[i][0] = 1;
        for(int i = 0; i < n; i++)  Path[0][i] = 1;
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++){
                Path[i][j] = Path[i-1][j] + Path[i][j-1];
            }
            
        int cnt = Path[m-1][n-1];
        return cnt;
    }
};
