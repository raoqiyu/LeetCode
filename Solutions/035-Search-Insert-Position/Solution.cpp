class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Binary Search
        
        int low = 0, high = nums.size() - 1, mid;
        
        while(low <= high){
            mid = (low+high)/2;
            // If the target us foundm return the index
            if(nums[mid] == target){
                return mid;
            // else, return the index where it would be if it were inserted in order
            }else if(nums[mid] < target){
                if(mid >= nums.size()-1 || nums[mid+1] > target)
                    return mid+1;
                else
                    low = mid + 1;
            }else if(nums[mid] > target){
                if(mid <= 0 || nums[mid-1] < target)
                    return mid;
                else
                    high = mid - 1;
            }
        }
    }
};
