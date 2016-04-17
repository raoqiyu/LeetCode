class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Dynamic programming
        // dp[i][j] == true: the first i+j characters of s3 is formed by the first i characters of s1 and the first j characters of s2
        // dp[i][j] = true if (dp[i-1][j] == true && s1[i-1] == s3[i+j-1]) or (dp[i][j-1] == true && s2[j-1] == s3[i+j-1])
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len1 + len2 != len3) return false;
        
        bool  dp[len1+1][len2+1];
        dp[0][0] = true;
        for(int i = 1; i <= len1; i++) dp[i][0] = (dp[i-1][0] && (s1[i-1] == s3[i-1]));
        for(int j = 1; j <= len2; j++) dp[0][j] = (dp[0][j-1] && (s2[j-1] == s3[j-1]));
        for(int i = 1; i <= len1; i++)
            for(int j = 1; j <= len2; j++){
                if(dp[i-1][j] && (s1[i-1] == s3[i+j-1]))
                    dp[i][j] = true;
                else if(dp[i][j-1] && (s2[j-1] == s3[i+j-1]))
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        
        return dp[len1][len2];
    }
};
