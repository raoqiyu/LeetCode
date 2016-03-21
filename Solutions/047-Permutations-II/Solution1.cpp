class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // store all permutations in sorted (lexicographic) order (with no repeated permutations)
        // 1. sort the given array in non-decreasing order
        // 2. generate the next high permutation
        //    2.1 find the right-most numbers which is smaller that next one
        //    2.2 find the ceiling of the right-most number. Ceiling is the smallest one on the right of number found in 2.1, 
        //         which is larger that the number found in 2.1
        //    2.3 swap the right-most one and the ceiling, then sort the sub-array in non-decreasing order after the original
        //         index if right-most number
        

        vector<vector<int>> ret;
        // Step 1
        sort(nums.begin(), nums.end());
        // Step 2
        int idx_rm, idx_ceil, idx_nums = nums.size()-1, i,ceil;
        while(true){
            ret.push_back(nums);
            // 2.1
            for(idx_rm = idx_nums-1; idx_rm >= 0; idx_rm --)
                if(nums[idx_rm] < nums[idx_rm+1]) break;
            if(idx_rm == -1) break;
            // 2.2
            for(i=idx_rm, ceil=INT_MAX; i <= idx_nums; i++){
                if(nums[i] > nums[idx_rm] && nums[i] < ceil){
                    idx_ceil = i;
                    ceil = nums[idx_ceil];
                }
            }
            // 2.3
            swap(nums[idx_rm], nums[idx_ceil]);
            sort(nums.begin()+idx_rm+1, nums.end());
            
        }
        return ret;
    }
private:

    void swap(int &x, int &y)
    {
        int temp = y;
        y = x;
        x = temp;
    }
};
