class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, s.size()-1, p, p.size()-1);
    }
private:
    bool isMatch(string s, int sidx, string p, int pidx)
    {
        if(sidx == -1 && pidx == -1)
            return true;
        if(p[pidx] == '.')
            return (sidx > -1 && isMatch(s, sidx-1, p, pidx-1));
        else if(p[pidx] == '*'){
            // Case 1 : '*' Matches zero of the preceding element.
            if (isMatch(s, sidx, p, pidx-2)) return true;
            // Case 2 : '*' Matches zero more of the preceding element.
            //          0...idx
            //          0...idx-1
            //          0...idx-2
            //          ......
            //          if s[k] == p[pidx-1] || p[pidx-1] == '.' is not satisfy, then all elements before it will not statisfy
            for(int k = sidx; k >= 0; k--){
                if( s[k] == p[pidx-1] || p[pidx-1] == '.'){
                    if(isMatch(s, k-1, p, pidx-2)) 
                        return true;
                }else
                    break;
            }
        }else if(sidx>-1 && s[sidx] == p[pidx])
            return isMatch(s, sidx-1, p, pidx-1);
        return false;
    }
};
