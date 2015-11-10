class Solution {
public:
    int longestValidParentheses(string s) {
        // Dynamic Programming
        // flag[i] : the longest valid parentheses substring between s[i]  and s[s.length()-1], and begin from s[i];
        // flag[s.length()-1] = 0
        // Goal : find the length of the longest valid (well-formed) parentheses substring
        // flag[i] : if s[i] = '(' check this case, else continue
        //              match = i+1+flag[i+1]
        //              if s[match] == ')' then flag[i] = flag[i+1] + 2  ->> ( (...) )
        //               else if s[i+1+flag[i+1]] != ')' then s[i] ...s[s.length()-1] do not have a substring with a valid parenthese.
        //              if match+1 < s.length : then connect two substring begin at s[i] and s[match+1]
        int len = s.length();
        int* flag = new int[len];
        memset(flag, 0, len*sizeof(int));
        int max_len = 0;
        int match = 0;
        for(int i = len-2; i >= 0; i--){
            // Only cosider the '(' case
            if(s[i] == '('){
                // find the possible match position
                // it may exist or not
                match = i+1 + flag[i+1];
                // ((....))
                if(match < len && s[match] == ')'){
                    flag[i] = flag[i+1] + 2;
                    // Key operation
                    // Connect two sub-match
                    // ((...))((...))
                    if(match+1 < len)
                        flag[i] += flag[match+1];
                }
            }
            if(flag[i] > max_len)
                max_len = flag[i];
        }
        delete flag;
        return max_len;
    }
};
