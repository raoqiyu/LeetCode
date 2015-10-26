class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /*
        1) sort the array nums in non-descending order
        2) fix the first element as nums[i] fix the second element as nums[i+1]
            do a 2-sum problem
       

        */

        vector<vector<int>> ret = {};
        int sizes = nums.size();
        if(nums.size() < 4) return ret;
        
        // Step 1
        sort(nums.begin(), nums.end());

        // Step 2
        for(int i = 0; i < sizes - 3; i++){
            // if the sum of four smallest elements is greater than target, then no pairs will statisify the condition
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            // if the sum of nums[i] and three maximum elements is smaller than target, then no combination including nums[i] will statisify
            if(nums[i]+nums[sizes-1]+nums[sizes-2]+nums[sizes-3] < target) continue;
            for(int j = i + 1; j < nums.size() -2; j++){
                // if the sum of four smallest elements is greater than target, then no pairs will statisify the condition
                if (nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
                // if the sum of nums[i] and nums[j] and two maximum elements is smaller than target, then no combination including nums[j] will statisify
                if(nums[i]+nums[j]+nums[sizes-1]+nums[sizes-2] < target) continue;
                int begin = j+1, end = sizes-1;
                while (begin < end){
                    int val = nums[i]+nums[j]+nums[begin]+nums[end];
                    if( val == target){
                        ret.push_back({nums[i], nums[j], nums[begin], nums[end]});
                        begin++;end--;
                        while(begin < end){
                            if (nums[begin] == nums[begin-1]) begin++;
                            else if( nums[end] == nums[end+1]) end--;
                            else break;
                        }
                    }else if( val < target){
                        begin++;
                    }else
                        end--;
                }
                while(j<sizes-1 && nums[j+1] == nums[j]) j++; 
            }
            while(i<sizes-1 && nums[i+1] == nums[i]) i++; 
        }        
        
        return ret;
        
    }
};
