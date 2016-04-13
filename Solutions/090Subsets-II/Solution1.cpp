class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // BackTracking 
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        dfs(nums, 0, tmp, ret);
        
        return ret;
    }
private:
    void dfs(vector<int>& nums, int n, vector<int> tmp, vector<vector<int>>& ret){
        ret.push_back(tmp);
        
        for(int i = n; i < nums.size(); i++){
            if(i > n && nums[i] == nums[i-1])
                continue;
            // with nums[i]
            tmp.push_back(nums[i]);
            dfs(nums, i+1, tmp, ret);
            tmp.pop_back();
        }
    }
};
