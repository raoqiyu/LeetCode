class Solution {
public:
    int numDecodings(string s) {
        // Dynamic Programming
        // w[i] : numbers of ways to decode substring s[0...i-1];
        // w[0] = 1,  w[1] =1
        // w[i] = w[i-1] + w[i-2] if s[i-1] != 0 &&  1 <= (s[i-1]s[i]) <= 26
        //      = w[i-2]          if s[i-1] == 0
        
        if(s.length() == 0 || s[0] == '0') return 0;

        vector<int> w(s.length()+1, 0);
        w[0] = w[1] = 1;
        
        for(int i = 2; i <= s.length(); i++){
            if(s[i-1] == '0' && (s[i-2] == '0' || s[i-2] > '2')) return 0;
            if(s[i-1] <= '6' && s[i-1] > '0'){
                if(s[i-2] <= '2' && s[i-2] >= '1')
                    w[i] = w[i-1] + w[i-2];
                else if(s[i-2] == '0')
                    w[i] = w[i-2];
                else 
                    w[i] = w[i-1];
            }else if(s[i-1] > '6'){
                if(s[i-2] == '1')
                    w[i] = w[i-1] + w[i-2];
                else
                    w[i] = w[i-1];
            }else
                w[i] = w[i-2];
        }
        
        return w[s.length()];
    }
};
