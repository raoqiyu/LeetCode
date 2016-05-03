class Solution {
public:
    string removeDuplicateLetters(string s) {
        // Greddy
        // Each time we select a character which has the smllest lexicographical order from left to right  util  we meet a non
        // -duplicate character which we cannot skip
        
        // Notice : 
        // when we meet a non-duplicate character, this means that we must select a character from the substring (s[0] .... s[pos])
        // which consists of character from beginning of the string s to the position of the non-duplicate character
        
        // The non-duplicate character has two kinds:
        //      1. it only appear once among the whole string s
        //      2. it appears many times, but we have met all of the duplicate position, this position is its last appearance
        //          so we should maintain characters' count of appearance.
        // Once we have selected a characer we must delete all same character after its position
        // find next character from the substring
        if(s.empty())
            return "";
            
        vector<int> cnts(26, 0);
        for(auto c : s)
            cnts[c-'a']++;
        // the position of the character we will select
        int pos = 0;
        for(int i = 0; i < s.length(); i++){
            // Select the smallest lexicographical order character among the duplicate characters
            if(s[i] < s[pos])
                pos = i;
            // update the cnts infomation of the chatacter we meet, 
            // if s[i] is non-duplicate, we select a character(s[pos]) immediately
            // pos is in [0...i]
            if(--cnts[s[i]-'a'] == 0)
                break;
        }
        cout <<pos << endl;
        char selected = s[pos];
        string sub_s;
        // delete all selected character after position of pos
        for(int i = pos+1; i < s.length(); i++)
            if(s[i] != selected)
                sub_s += s[i];
        
        // find next character form the substring
        string ret = selected + removeDuplicateLetters(sub_s);
        
        return ret;
    }
};
