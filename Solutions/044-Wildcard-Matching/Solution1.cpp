class Solution {
public:
    bool isMatch(string s, string p) {
        // Greedy
        // ? matches 0 char
        // * matches 0,1,2,3,4,...
        int sIdx = 0, pIdx = 0;
        int startPos = -1, sMatch = -1;
        int sLen = s.length(), pLen = p.length();
        
        while(sIdx < sLen){
            if(s[sIdx] == p[pIdx] || p[pIdx] == '?'){
                sIdx++; pIdx++; continue;
            }
            
            // Case 1: * matches 0  char
            if(p[pIdx] == '*'){
                startPos = pIdx;
                pIdx++;
                sMatch = sIdx;
                continue;
            }
            // Case 2: * matches 1,2,3,... 
            if(startPos != -1){
                pIdx = startPos+1;
                sIdx = sMatch++;
                continue;
            }
            return false;
        }
        // If there are * left at p, omit
        while(pIdx < pLen && p[pIdx] == '*') pIdx++;
        return pIdx == pLen;
    }

};
