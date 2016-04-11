class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Dynamic Programming 
        // Divide s1/s2 into substring with length k and len-k. Then check if the two substrings 
        // s1[0...k-1] and s1[k, len-1] are the scrambles of (s2[0..k-1] and s2[k, len-1])/(s2[len-k..len-1] and s2[0, len-k-1])
        
        // ret[k][i][j] == 1 : s1[i...i+k] can be scrambled from s2[j...j+k], 
        int len = s1.length();
        if(len != s2.length()) return false;
        if(len == 0) return true;
        
        vector<vector<vector<int>>> ret(len, vector<vector<int>>(len, vector<int>(len, false)));
        
        for(int i = 0; i < len; i++)
            for(int j = 0; j < len; j++)
                ret[0][i][j] = (s1[i] == s2[j]);
        
        for(int k = 2; k <= len; k++)
            for(int i = len - k; i > -1; i--)
                for(int j = len - k; j > -1; j--){
                    bool t = false;
                    for(int l = 1; l < k && !t; l++){
                        t = (ret[l-1][i][j] && ret[k-l-1][i+l][j+l]) ||
                            (ret[l-1][i][j+k-l] && ret[k-l-1][i+l][j]);
                    }
                    ret[k-1][i][j] = t;
                }
        return ret[len-1][0][0];
    }
};
