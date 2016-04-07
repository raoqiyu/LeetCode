class Solution {
public:
    string minWindow(string s, string t) {
        // Two pointers (begin pointer and end pointer)
        // Maintain a sub-window of s which contains T
        // Expand end pointer to include new element of s in sub-window
        // Shrink begin pointer to exclude useless element of sub-window
        int s_len = s.length(), t_len = t.length();
        // Two pointer
        int begin=0, end=0;
        // Hash table
        int T_have[256] = {0};
        int S_find[256] = {0};
        for(auto c : t)
            T_have[c]++;
        // Target 
        int min_win_len = INT_MAX;
        int min_begin;
        //
        int temp_win_len = 0, count = 0;
        for(; end < s_len; end++){
            // Skip character not in T
            if(T_have[s[end]] == 0) continue;
            
            // Expand end pointer
            S_find[s[end]]++;
            if(S_find[s[end]] <= T_have[s[end]])
                count++;
            
            // get a sub-window
            if(count == t_len){
                // Shrink begin pointer
                while(begin < end){
                    if(T_have[s[begin]] == 0){
                        begin++;
                    }else if(S_find[s[begin]] > T_have[s[begin]]){
                        S_find[s[begin]]--;
                        begin++;
                    }else
                        break;
                }
                
                // Update the minimum information
                temp_win_len = end - begin + 1;
                if(temp_win_len < min_win_len){
                    min_begin = begin;
                    min_win_len = temp_win_len;
                }
            }
        }
        
        return (min_win_len==INT_MAX)? "" : s.substr(min_begin, min_win_len);
    }
};
