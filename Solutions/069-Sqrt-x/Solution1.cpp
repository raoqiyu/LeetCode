class Solution {
public:
    int mySqrt(int x) {
        // Binary Search
        if(x <= 1)
            return x;
        int l = 0, h = x/2;
        while(l <= h){
            long m = (l+h)/2;
            if( m * m == x )
                return m;
            else if(m * m > x)
                h = m - 1;
            else
                l = m + 1;
        }
        return h > l?l:h;
    }
};
