class Solution {
public:
    #define INT_MAX 2147483647
    #define INT_MIN -2147483648
    int reverse(int x) {
        long ret = 0;
    //  int sign = 1;
    //  if (x >= 0){
    //      sign = 1;
    //      x = abs(x); 
    //    } 
        while(x){
            ret = ret*10 + x%10;
            x /= 10;
        }
    //  ret *= sign;
        if(ret < INT_MIN || ret > INT_MAX)
            return 0;
        return ret;
    }
};
