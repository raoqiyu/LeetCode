class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Store <char, it's last index if it apperence in s>
        vector<int> char_visited(256,-1);
        int longest = 0, Len = 0;
        for(int i = 0; i < s.size(); i++){
            // If s[i] is a new character, update Len
            // If it has already in the string, we have two case
            // Case 1 :
            // If it does not in the current substring, we simply increase the len
            if(char_visited[s[i]] < i - Len)
                Len++;
            // Case 2 :
            // If it is in the current substring, we shrink the len
            else
                Len = i - char_visited[s[i]];
            
            // update the character's index, by doing this we can make the index to be the newest index
            char_visited[s[i]] = i;
            // Update longest
            if( longest < Len)
                longest = Len;
        }
        
        return longest;
    }
};
