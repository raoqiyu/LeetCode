class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        ret.push_back(temp);
        sub(0, nums, temp);
        return ret;
    }
private:
    vector<vector<int>> ret;
    void sub(int i, vector<int> &nums, vector<int> &temp){
        if(i < nums.size()){
            // with i
            temp.push_back(nums[i]);
            ret.push_back(temp);
            sub(i+1, nums, temp);
            // without i
            temp.pop_back();
            sub(i+1, nums, temp);
        }
        
    }
};
