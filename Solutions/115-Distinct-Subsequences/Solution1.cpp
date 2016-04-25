class Solution {
public:
    int numDistinct(string s, string t) {
        // Dynamic Programming
        int s_len = s.size(), t_len = t.size();
        if(t_len == 0 || s_len < t_len) return 0;
        if(t_len == s_len) return s == t;
        
        // cnt[i] : the number of distinct subsequences of T[0...i] in S
        int cnt[t_len];
        for(int j = 0; j < t_len; j++) cnt[j] = 0;
        for(int i = 0; i < s_len; i++){
            int chr = s[i];
            int j_end = t_len-1;
            if(j_end > i) j_end = i;
            for(int j = j_end; j > 0; j--)
                if(t[j] == chr) cnt[j] += cnt[j-1];
            if(t[0] == chr) cnt[0]++;
        }
        return cnt[t_len-1];
    }
};
