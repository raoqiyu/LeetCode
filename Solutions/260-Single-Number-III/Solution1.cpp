class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> tmp;
        vector<int> ret;
        
        for(auto n : nums){
            auto it = tmp.find(n);
            if(it == tmp.end()){
                tmp.insert(n);
            }else{
                tmp.erase(it);
            }
        }
        
        for(auto n : tmp)
            ret.push_back(n);
            
        return ret;
    }
};
