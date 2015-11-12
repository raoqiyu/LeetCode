class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Binary Search
        int low = 0, high = nums.size()-1, mid;
        vector<int> ret(2,-1);
        // Find th target value
        while(low <= high){
            mid = (low+high)/2;
            if(nums[mid] == target)
                break;
            else if(nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        // If the target value is not found in the array
        if(low > high)
            return ret;
        // Find the starting and ending position of target value
        int begin=mid, end=mid;
        while(begin >= 0 && nums[begin] == target) begin--;
        while(end < nums.size() && nums[end] == target) end++;
        ret[0] = begin+1; ret[1] = end-1;
        return ret;
    }
};
