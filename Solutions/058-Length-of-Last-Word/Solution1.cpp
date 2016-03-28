class Solution {
public:
    int lengthOfLastWord(string s) {
        int last_len= 0;
        
        // Skip the last space character
        auto c =  s.rbegin();
        while(*c == ' ') c++;
        // Count the last word
        for(; c != s.rend() && *c != ' '; c++)
            last_len++;
            
        return last_len;
    }
};
