class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        // Divide and Conquer
        // 1) Divide the given array into two halves
        // 2) Return the maximum of following
        //      a) Maximum subarray sum in left half
        //      b) Maximum subarray sum in right half
        //      c) Maximum subarray sum such the the subarray across the midpoint
        
        int maxSum;
        int l = 0, h = nums.size()-1;
        maxSum = maxSubarray(nums, l, h);
        return maxSum;
    }
private:
    int maxSubarray(vector<int>& nums, int l, int h)
    {
        if(l == h)
            return nums[l];
            
        int mid = (l + h) / 2;
        
        int left = maxSubarray(nums, l , mid);
        int right = maxSubarray(nums, mid+1, h);
        int cross = maxCrossing(nums, l, mid, h);
        if(left < right)
            return max(right, cross);
        else
            return max(left, cross);
    }
    int maxCrossing(vector<int>& nums, int l, int mid, int h)
    {
        int leftSum = INT_MIN, rightSum = INT_MIN;
        int temp = 0;
        for(int i = mid; i >= l; i--){
            temp += nums[i];
            if(leftSum < temp)
                leftSum = temp;;
        }
        temp = 0;
        for(int j = mid+1; j <= h; j++){
            temp += nums[j];
            if(rightSum < temp)
                rightSum = temp;
        }
        return leftSum + rightSum;
    }
};
