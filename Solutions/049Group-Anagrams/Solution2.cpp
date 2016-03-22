class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> AnaIdx;
        vector<vector<string>>  ret;        
        // keep lexicographic order
        sort(strs.begin(), strs.end());
        // Scan the strs, record the anagrams in format:
        // ret : record the anagrams, AnaIdx : record the anagrams's index in ret 
        for(auto s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            auto f = AnaIdx.find(temp);
            // if not dound
            if(f == AnaIdx.end()){
                // push this anagrams into ret and record its index
                ret.push_back(vector<string>({s}));
                AnaIdx[temp] = ret.size()-1;
            }else{
                // if found, push this s into its anagrams array
                ret[f->second].push_back(s);
            }
        }
        
        return ret;
    }
};
