class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size()-1;
        for(int i = n; i > -1; i--){
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        
        if(carry == 1)
            digits.insert(digits.begin(), 1);
            
        return digits;
    }
};
