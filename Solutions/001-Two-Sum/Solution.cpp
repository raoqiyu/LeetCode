class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Save all visited numbers and corresponding index
        map<int, int> nums_visited;
        // Save return indices
        vector<int> ret;
        // Scan the array of integers
        for(int i = 0; i < nums.size(); i++){
            // Check if there exists a number satisfy the condition
            // If there is , return ;
            if (nums_visited.find(target-nums[i]) != nums_visited.end()){
                ret.push_back(nums_visited[target-nums[i]]);
                ret.push_back(i+1);
                return ret;
            }
            // Else insert the current element into map
            if(nums_visited.find(nums[i]) == nums_visited.end())
                nums_visited[nums[i]] = i+1;
        }
    }
};
