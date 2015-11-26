class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // BackTracking
        vector<int>  combination;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, combination, 0, target, 0);
        return ret;
    }
private:
    vector<vector<int>>  ret;
    void dfs(vector<int>& candidates, vector<int>& comb, int sum, const int& target, int idx)
    {
        // if arrive the end, backbracking
        if(idx == candidates.size())
            return;
        // if this combination statify the requirement, save
        if(sum == target){
            ret.push_back(comb);
            return;
        // if sum > target, pruning
        }else if (sum > target){
            return ;
        // dfs
        }else{
            //The same repeated number may be chosen from C unlimited number of times.
            // so, we begin at idx, not idx+1
            for(int i = idx; i < candidates.size(); i++){
                comb.push_back(candidates[i]);
                dfs(candidates, comb, sum+candidates[i], target, i);
                comb.pop_back();
            }
        }
    }
};
