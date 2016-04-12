class Solution {
public:
    bool isUgly(int num) {
      // eliminate all 2, 3 and factors, if the left is 1 then true or false
        if(num == 1)
            return true;
        if(num <= 0)
            return false;
            
        while(num >= 2 && num %2 == 0) num /= 2;
        while(num >= 3 && num %3 == 0) num /= 3;
        while(num >= 5 && num %5 == 0) num /= 5;
        
        if(num == 1)
            return true;
        return false;
    }
};
