class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
        // if this combination statify the requirement, save
        if(sum == target){
            ret.push_back(comb);
            return;
        // dfs
        }else{
            //Each number in C may only be used once in the combination.
            // so, we begin at idx+1, not idx
            //      when dfs, dfs(*,*,*,*,i+1)
            for(int i = idx; i < candidates.size(); i++){
                // if sum > target, pruning
                if (sum+candidates[i] > target) continue;
                comb.push_back(candidates[i]);
                dfs(candidates, comb, sum+candidates[i], target, i+1);
                comb.pop_back();
                // To avoid [1,7],[1,7] cases
                // if we have two 1( [1,1,....,7])
                // wo, without the while loop, it will produce two duplicate solutions([1,7],[1,7])
                // we need to skip all values same as current value
                while(i<candidates.size()-1 && candidates[i]==candidates[i+1]) i++; 
            }
        }
    }
};
