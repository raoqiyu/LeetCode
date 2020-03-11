class Solution:
    def longestPalindrome(self, s: str) -> str:
        """
        dp[i][j] = 1 <-> dp[i+1]dp[j-1] == 1 and s[i] == s[j]
        """
        n = len(s)
        if n <= 1:
            return s
        
        dp = [[False for _ in range(n)] for _ in range(n)]
        max_len, max_s = 1, s[0]
        for j in range(n):
            dp[j][j] = True
            for i in range(j-1, -1, -1):
                if i+1 <= j-1 and dp[i+1][j-1] and s[i] == s[j]:
                    dp[i][j] = True
                elif i+1 > j-1 and s[i] == s[j]:
                    dp[i][j] = True
                
                if dp[i][j] and  max_len < j-i+1:
                    max_len = j-i+1
                    max_s = s[i:j+1]
                
        
        return max_s
