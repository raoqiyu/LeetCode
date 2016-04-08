class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Binary Search
        int size = nums.size();
        int low = 0, high = size-1, mid;
        while(low <= high){
            mid = (low+high)/2;
            if(nums[mid] == target)
                 return true;
            else if(nums[mid] < nums[high]){
                if(nums[mid] < target && nums[high] >= target)
                    low = mid+1;
                else
                    high = mid-1;
            }else if(nums[mid] > nums[high]){
                if(nums[mid] > target && nums[low] <= target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }else{
                high--;
            }
        }
        return false;
    }
};
