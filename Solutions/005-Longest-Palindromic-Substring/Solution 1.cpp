class Solution {
public:
    string longestPalindrome(string s) {
    // Dynamic Programming
    // flag[i[[j] == 1: s[i...j] is a palindromic string
    // flag[i][i] is always 1, because of 1 char is always palindromic
    // flag[i][j] (j > i) is 1 iff flag[i+1][j-1] is 1 and s[i] == s[j]
    
        int n = s.size();
        bool flag[n][n] = {0};
        int i;
        
        // Check : length = 1
        int maxlen = 1, start_index = 0;;
        for(i = 0; i < n; i++)
            flag[i][i] = 1;
        
        // Check : length = 2
        for(i = 0; i < n - 1; i++)
            if( s[i] == s[i+1]){
                flag[i][i+1] = 1;
                start_index = i;
                maxlen = 2;
            }
         
        // Check : length >= 3
        for(int len = 3; len <= n; len++){
            for( i = 0; i < n-len+1; i++){
                int j =  i + len - 1;
                if(flag[i+1][j-1] == 1 && s[i] == s[j]){
                    flag[i][j] = 1;
                    if(len > maxlen){
                        maxlen = len;
                        start_index = i;
                    }
                }    
            }
        }
        return s.substr(start_index, maxlen);
    }
};
