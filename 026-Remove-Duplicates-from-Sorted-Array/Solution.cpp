class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Scan the array with a pointer, omit all values which is same as its
        // previous on, that means we just count values we meet the first time
        if(nums.size() == 0) return 0;
        int cnt = 1;
        for(int i = 1; i < nums.size(); i++){
            if( nums[i] != nums[i-1] ){
                cnt++;
                nums[cnt-1] = nums[i];
            }
        }
        return cnt;
    }
};
