class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        """
        dp[i][j]: count of unique paths to reach here
        
        dp[0][j] = 1
        dp[i][0] = 1
        
        dp[i][j] = dp[i-1][j] + dp[i][j-1]
        """
        if n == 1 and m == 1:
            return 1
        
        dp = [[1 for _ in range(m)] for _ in range(n)]
            
        for i in range(1, n):
            for j in range(1, m):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
                
        return dp[n-1][m-1]
        
