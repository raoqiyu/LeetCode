class Solution {
public:
    int getSum(int a, int b) {
        int ret=0;
        int carry = 0;
        int ai,bi, s;
        for(int i = 0; i < 32; i++){
            ai = (a>>i) & 0x1;
            bi = (b>>i) & 0x1;
            s = ai ^ bi ^ carry;
            ret |= (s<<i);
            
            carry = (ai&bi) || ( (ai^bi) & carry);
        }
        
        return ret;
    }
};
