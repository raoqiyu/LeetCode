class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Dynamic Programming
        // tempSum[i] : the maximum subarray end with nums[i]
        // if tempSum[i-1] < 0 then tempSum[i] = nums[i] else tempSum[i] = tempSum[i-1]+nums[i]
        int maxSum = INT_MIN, tempSum = -1;
        
        for(auto n : nums){
            if(tempSum < 0){
                tempSum = n;
            }else{
                tempSum += n;
            }
            maxSum = max(maxSum, tempSum);
        }
        
        return maxSum;
    }
};
