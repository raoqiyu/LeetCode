class Solution {
public:
    #define INT_MAX 2147483647
    #define INT_MIN -2147483648
    int myAtoi(string str) {
        int index = 0;
        // Discard all white space
        while(str[index] ==  ' ')
            index++;
        int sign = 1;
        // Check if there exists + or -
        switch (str[index]) {
            case '-' :
                sign = -1;
                index++;
                break;
            case '+' :
                sign = 1;
                index++;
                break;
        }
        // Check valid input
        // Calculate
        // long long is not enough
        long double  ret = 0;
        for(; index < str.size(); index++){
            if(str[index] - '0' > 9 || str[index] - '0' < 0){
                break;
            }
            ret = ret*10 + str[index]-'0';
        }
            
        ret *= sign;
        if(ret > INT_MAX)
            return INT_MAX;
        if(ret < INT_MIN)
            return INT_MIN;
        return ret;
    }
};
