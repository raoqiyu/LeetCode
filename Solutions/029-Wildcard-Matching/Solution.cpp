class Solution {
private:
    long mul(long  x, long y)
    {
        long ret = 0;
        for(; y >0; y >>= 1){
            (y & 1) && (ret += x);
            x += x;
        }
        return ret;
    }
public:
    int divide(int dividend, int divisor) {
        // Check Overflow case
        // Store the flag of return value
        // Use long type integer to avoid overflow
        long  dd = dividend, ds = divisor;
        int flag = 1;
        if(dd < 0){
             flag *= -1;
             dd *= -1;
        }
        if(ds < 0){
            flag *= -1;
            ds *= -1;
        }
        
        long  begin = 0, end = dd+1;
        long  mid = (begin + end) >> 1, prod = 0;
        // Binary Search
        while(begin < end){
            prod = mul(mid, ds);
            if( prod > dd)
                end = mid -1;
            else if( prod < dd)
                begin = mid+1;
            else
                break;
            mid = (begin + end) >> 1;
        }
        if(mul(mid, ds) > dd) mid--;
        
        // Check wether mid is overflow
        if( flag > 0 && mid > INT_MAX) return INT_MAX;
        return mid*flag;
    }
};
