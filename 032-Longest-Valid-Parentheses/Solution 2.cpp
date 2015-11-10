class Solution {
public:
    int longestValidParentheses(string s) {
        // 1. setup a mark array
        // 2. mark all valid parenteses
        // 3. find the longest sub-array in array which's values are true
        int len = s.size();
        // 1
        bool *marked = new bool[len];
        memset(marked, 0, len);
        stack<int> visited;
        
        // 2
        for(int i=0; i < len; i++){
            if(s[i] == '(')
                visited.push(i);
            else if(s[i] == ')' && !visited.empty()){
                marked[i] = true;
                marked[visited.top()] = true;
                visited.pop();
            }
        }
        // 3
        int curr_len = 0, max_len = 0;
        for(int i = 0; i < len; i++){
            if(marked[i] == true)
                curr_len++;
            else{
                max_len = max(max_len, curr_len);
                curr_len = 0;
            }
        }
        max_len = max(max_len, curr_len);
        return max_len;
    }
};
