class Solution {
public:
    double myPow(double x, int n) {
        // Special case
        if(n == 0)
            return 1.0;
        if(n < 0){
            if( n == INT_MIN)
                return 1.0 / (myPow(x,INT_MAX)*x);
            else
                return 1.0 / myPow(x, -n);
        }
        // e.g,
        // n = (1101 0101)  --> a binary representation
        // x^n = x^128 * x^64 * x^16 * x^4 * x^1
        // Loop though each bit, if the i-th bit is 1 ,then add x^(1 << i) to the result;
        double ret = 1.0;
        for(; n > 0; x *= x, n>>= 1){
            if(n & 1)
                ret *= x;
        }
        
        return ret;
    }
};
