class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // BackTracking
        ret.clear();
        permutation(nums,0);
        return ret;
    }
private:
    vector<vector<int>> ret;
    void permutation(vector<int> &nums, int idx)
    {
        if(idx == nums.size()){
            ret.push_back(nums);
            return;
        }
        
        for(int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            permutation(nums, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
    void swap(int &x, int &y)
    {
        int temp = y;
        y = x;
        x = temp;
    }
};
