class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // Dynamic Programming
        // dp[i][j] : the maximum coins I can gollect by bursting the balloons from nums[i] to nums[j]
        // let K,   i < k < j,: nums[k] is the last balloon I burst in the subarray i..j
        // for(m = k+1 : j-1)
        //     dp[i][j] = max(dp[i][j], nums[i]*nums[k]*nums[j] + dp[i][j] + dp[k][j])
        // Initialization
        // dp[i][i] = dp[i][i+1] = 0
        // dp[i][i+2] = nums[i]*nums[i+1]*nums[i+2]
        // Step :
        // first get all values : dp[i][i+2] for i = 0 .. m
        // then dp[i][i+3] for i = 0 .. m, dp[i][i+4] for i = 0 .. m , ............
        int n = nums.size() + 2;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int m = 2; m < n; m++){
            for(int i = 0; i+m < n; i++){
                int j = i + m;
                for(int k = i+1; k < j; k++)
                    dp[i][j] = max(dp[i][j], nums[i]*nums[k]*nums[j]+dp[i][k]+dp[k][j]);
            }
        }
        
        return dp[0][n-1];
    }
};
