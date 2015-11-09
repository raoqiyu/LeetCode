class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Generate the next high permutation
        if(nums.size() < 2) return;
        int ridx = nums.size();
        int i;
        // Step 1 : find the rightmost num position which is smaller than its next num, we call this ridx
        for(i = nums.size()-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ridx = i;
                break;
            }
        }
        if(i == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        // Step 2 : find the ceiling position of the ridx num from right of ridx
        int cidx = ridx+1;
        for(i = ridx + 1; i < nums.size(); i++){
            if(nums[i] > nums[ridx] && nums[i] < nums[cidx]){
                cidx = i;
            }
        }
        // Step 3 : swap the ridx num and cidx num
        int temp = nums[cidx];
        nums[cidx] = nums[ridx]; nums[ridx] = temp;
        // Step 4 : sort the sub array ater ridx
        sort(nums.begin()+ridx+1, nums.end());
    }
};
