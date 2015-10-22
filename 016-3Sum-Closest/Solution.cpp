class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = -100000;;
        int length = nums.size();
        if( length == 0) return 0;
        // sort the origin array, make it possible to use two pointer
        sort(nums.begin(),nums.end());
        for(int i = 0; i < length - 2; i++){
            // Use two pointer
            // Avoid dong same operation on same numbers
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int start = i + 1, end = length-1;
            while(start < end){
                int val = nums[i] + nums[start] + nums[end];
                if (val == target){
                    return target;
                }else if ( (val < target)) {
                    
                    start++;
                }else{
                    end--;
                }
                if ( abs(val - target) < abs(ret - target) ) ret = val;
            }
        }
        return ret;
    }
};
