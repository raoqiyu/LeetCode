class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Two pointers
        int ptr1 = 2;
        if(nums.size() < 2) return nums.size();
        for(int ptr2 = 2; ptr2 < nums.size(); ptr2++){
            if(nums[ptr2] != nums[ptr1-1] || nums[ptr2] != nums[ptr1-2])
                nums[ptr1++] = nums[ptr2];

        }
        return ptr1;
    }
};
