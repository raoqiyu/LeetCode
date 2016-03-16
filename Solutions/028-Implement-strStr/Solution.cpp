class Solution {
private:
    vector<int> computeLPS(string &pattern)
    {
        int l = pattern.size();
        vector<int>  lps(l, 0);
        int len = 0, i = 1;
        
        // Calucate lps[i] for i from 1 to l
        while(i < l){
            // if pattern[len] and pattern[i] match, we increment len by 1
            // and assign the incremented value to lps[i]
            if( pattern[len] == pattern[i]){
                len++;
                lps[i++] = len;
            }else{
                // if they donot mathch
                // and len is not 0, we use lps[len-1]'s information to update len
                // pattern[0...lps[len-1]-1] == pattern[(len-lps[len-1])......(len-1)]
                // so we continue use pattern[lps[len-1]] to match pattern[i]
                if( len != 0)
                    len = lps[len-1];
                else{
                    // if len is 0.
                    lps[i++] = 0;
                }
            }
        }
        return lps;
    }
public:
    int strStr(string haystack, string needle) {
        // KMP algorithm
        if( needle.size() == 0) return 0;
        vector<int>  lps = computeLPS(needle);
        int nidx = 0, hidx = 0, nlength=needle.size(), hlength=haystack.size();
        while( hidx < hlength){
            if( haystack[hidx] == needle[nidx]){
                hidx++; nidx++;
            }
            if( nidx == nlength)
                return hidx - nidx;
            else if( hidx < hlength && haystack[hidx] != needle[nidx]){
                if (nidx > 0)
                    nidx = lps[nidx-1];
                else 
                    hidx++;
            }
                
        }
        return -1;
    }
};
