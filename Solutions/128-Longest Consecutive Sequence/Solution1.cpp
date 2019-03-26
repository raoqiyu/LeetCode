class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        allNums.clear();
        int n_nums = nums.size();
        if(n_nums == 0) return 0;
        for(int i = 0; i < n_nums; i++)
            allNums.insert(nums[i]);
        
        int max_len = 0;
        for(int i = 0; i < n_nums; i++){
            int endwithI   = getCnt(nums[i], false);
            int beginwithI = getCnt(nums[i]+1, true);
            if(endwithI + beginwithI > max_len)
                max_len = endwithI + beginwithI;
        }
        return max_len;
    }
    
private:
    set<int> allNums;
    int getCnt(int val, bool Order){
        int len = 0;
        while(allNums.find(val) != allNums.end()){
            len++;
            allNums.erase(val);
            if(Order == true)
                val++;
            else
                val--;
        }
        return len;
    }
};
