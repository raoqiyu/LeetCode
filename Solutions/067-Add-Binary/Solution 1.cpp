class Solution {
public:
    string addBinary(string a, string b) {
        int a_len = a.length(), b_len = b.length();
        int carry = 0;
        string c;
        int ai, bj;
        for(ai = a_len-1, bj = b_len-1; ai >-1 && bj > -1; ai--,bj--){
            int t = (a[ai]-'0') + (b[bj]- '0') + carry;
            carry = t / 2;
            t %= 2;
            char tc = '0' + t;
            c = tc + c;
        }
        while(ai > -1){
            int t = (a[ai]-'0') + carry;
            carry = t / 2;
            t %= 2;
            char tc = '0' + t;
            c = tc + c; 
            ai--;
        }
        while(bj > -1){
            int t = (b[bj]-'0') + carry;
            carry = t / 2;
            t %= 2;
            char tc = '0' + t;
            c = tc + c; 
            bj--;
        }
        if(carry == 1)
            c = "1" + c;
            
        return c;
    }
};
