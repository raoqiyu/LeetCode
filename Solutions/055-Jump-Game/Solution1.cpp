class Solution {
public:
    bool canJump(vector<int>& nums) {
        //Greedy
        
        // If no zeor in nums, that's OK
        // If there is a zero, then we should have the ability to jump over it. 
        //      If we do not have that ability, we cannot reach the last index
        int len = nums.size();
        if(len < 2)
            return true;
        if(nums[0] == 0)
            return false;
        
        // scan the array step by step, if there is an item in nums we can not jump over, return false
        
        // n_jump : the maximum step we can jump now
        int n_jump = nums[0];
        for(int i = 1; i < len; i++){
            // consume 1 step
            n_jump--;
            // update maximum step
            if(nums[i] > n_jump)
                n_jump = nums[i];
            // if no more step can move and not reach the last index, return false;
            if(n_jump == 0 && i < len-1)
                return false;
        }
        return true;
    }
};
