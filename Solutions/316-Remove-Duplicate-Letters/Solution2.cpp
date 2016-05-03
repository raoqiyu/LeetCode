class Solution {
public:
    string removeDuplicateLetters(string s) {
        // Greddy
        // Each time we select a smaller character from left to right
        // ret : is a string contains characted we already selected
        // when we meet a new character
        //      if c in already in ret, just continue
        //      if c is smaller than ret's last character and the charcter has duplicate one after c, remove the last character and 
        //          push c into ret
        //      else, just push c into ret
        if(s.empty())
            return "";
        
        string ret = " ";
        vector<int>  cnts(26,0);
        vector<bool> used(26,false);
        for(auto c : s)
            cnts[c-'a']++;
        
        for(auto c : s){
            cnts[c-'a']--;
            // if already in ret, just continue
            if(used[c-'a'])
                continue;
            // if c is smaller than ret.back() and has duplicate one
            while(c < ret.back() && cnts[ret.back()-'a'] > 0){
                used[ret.back()-'a'] = false;
                ret.pop_back();
            }
            ret += c;
            used[c-'a'] = true;
            
        }
        
        return ret.substr(1);
    }
};
