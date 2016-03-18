class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // In-place swap
        // Firstly, turn the nums array into such one : position i holds number i+1
        // Secondly, find the first idx which nums[idx] != idx+1
        
        // In-place swap
        // Step 1
        int idx = 0;
        if(nums.size() <= 0) return 1;
        while(idx < nums.size()){
           if(nums[idx] > 0 && nums[idx] != idx+1 && nums[idx]-1 < nums.size() && nums[nums[idx]-1] != nums[idx] ){
                int temp = nums[idx];
                nums[idx] = nums[nums[idx]-1];
                nums[temp-1] = temp;
            }
            else
                idx++;
        }

        // Step 2
        for(idx = 0; idx < nums.size(); idx++)
            if(nums[idx] != idx+1)
                return idx+1;
                
        return nums.size()+1;
    }
};
