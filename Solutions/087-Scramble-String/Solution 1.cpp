class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Recursion 
        string tmp1 = s1, tmp2 = s2;
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        if(tmp1 != tmp2) return false;
        int n = s1.length();
        if(n == 1) return true;
        
        string s1_l, s1_r, s2_l, s2_r;
        bool ret = false;
        int idx = 1;
        while(idx < n && !ret){
            s1_l = s1.substr(0, idx);
            s1_r = s1.substr(idx);
            s2_l = s2.substr(0, idx);
            s2_r = s2.substr(idx);
            cout << s1 << " "  << s2 << endl;
            cout << s1_l << " "  << s1_r << " "  << " "  << s2_l << " " << s2_r << endl << endl;
            ret = isScramble(s1_l, s2_l) && isScramble(s1_r, s2_r);
            if(!ret){
                cout << "break" << endl;
                s2_l = s2.substr(0, n-idx);
                s2_r = s2.substr(n-idx);
                ret = isScramble(s1_l, s2_r) && isScramble(s1_r, s2_l);
            }
            idx++;
        }
        return ret;
    }
};
