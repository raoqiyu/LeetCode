class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> Anamap;
        
        // follow the lexicographic order
        sort(strs.begin(), strs.end());
        
        // Scan the strs, record the anagrams in format:
        // <sorted anagrams,<idx1, idx2, idx3, ....>
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            Anamap[temp].push_back(i);
        }
        
        // 
        vector<vector<string>>  ret;
        for(auto a : Anamap){
            vector<string> temp;
            for(auto i : a.second){
                temp.push_back(strs[i]);
            }
            ret.push_back(temp);
        }
        
        return ret;
    }
};
