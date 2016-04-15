class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        vector<string> ip;
        backtrack(0, 0, s, ret, ip);
        
        return ret;
    }
private:
    void backtrack(int startIdx, int segment, string &s, vector<string> &ret, vector<string> &ip){
        if(startIdx >= s.length() && segment != 4) return;
        if(startIdx != s.length() && segment == 4) return;
        if(startIdx == s.length() && segment == 4){
            ret.push_back(ip[0]+"."+ip[1]+"."+ip[2]+"."+ip[3]);
        }
        
        for(int i = startIdx; i < s.length() && i < startIdx+3; i++){
            string tmp = s.substr(startIdx, i - startIdx + 1);
            
            if(stoi(tmp) > 255)
                continue;
            ip.push_back(tmp);
            backtrack(i+1, segment+1, s, ret, ip);
            ip.pop_back();
            
            if(s[startIdx] == '0')
                return;
        }
    }
};
