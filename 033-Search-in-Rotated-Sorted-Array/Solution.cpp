class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Binary Search
        int size = nums.size();
        int low = 0, high = size-1, mid;
        while(low <= high){
            mid = (low+high)/2;
            if(nums[mid] == target)
                 return mid;
            else if(nums[mid] < target){
                if(nums[low] <= nums[mid]){
                    low = mid+1;
                }else if(nums[high] < target ){
                    high = mid-1;
                }else
                    low = mid+1;
            }else if(nums[mid] > target){
                if(nums[low] <= nums[mid]){
                    if(nums[low] > target){
                        low = mid+1;
                    }else{
                        high = mid-1;
                    }
                }else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};
