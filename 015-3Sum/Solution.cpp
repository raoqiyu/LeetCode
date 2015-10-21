class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret = {};
        vector<int> arr(3,0);
        int length = nums.size();
        if( length == 1) return ret;
        // sort the origin array, make it possible to use two pointer
        sort(nums.begin(),nums.end());
        for(int i = 0; i < length - 2; i++){
            // Use two pointer
            // Avoid dong same operation on same numbers
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int start = i + 1, end = length-1;
            int sum2 = -nums[i];
            while(start < end){
                int val = nums[start] + nums[end];
                if (val == sum2){
                    arr[0] = nums[i]; arr[1] = nums[start]; arr[2] = nums[end];
                    ret.push_back(arr);
                    start++;end--;
                    // avoid checking on same numbers
                    while(start < end){
                        if(nums[start] == nums[start-1])
                            start++;
                        else if (nums[end] == nums[end+1]){
                            end--;
                        }else
                            break;
                    }
                }else if ( val < sum2) {
                    start++;
                }else 
                    end--;
            }
        }
        return ret;
    }
};
