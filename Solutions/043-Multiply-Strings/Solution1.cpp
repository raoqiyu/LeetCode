class Solution {
public:
    string multiply(string num1, string num2) {
        string s3 = num1;
        if(num1.size() > num2.size()){
            num1 = num2; num2=s3;
        }
        if(num1.size() == 1){
            if(num1[0] == '1') return num2;
            if(num1[0] == '0') return "0";
        }
        string mul, temp;
        stringstream ss;
        int carry,idx=0;
        for(auto p = num1.rbegin(); p != num1.rend(); p++){
            temp = "";carry=0;
            int t, p_val = *p - '0', q_val;
            // Calculate single multiplication
            for(auto q = num2.rbegin(); q != num2.rend(); q++){
                q_val = *q - '0';
                t = p_val * q_val + carry;
                carry = t/10;
                t = t%10;
                ss << t;
            }
            if(carry > 0) ss << carry;
            ss >> temp; ss.clear();
            reverse(temp.begin(), temp.end());
            // Add to the whole multiplication
            if(mul.size() == 0)
                mul = temp;
            else{
                for(int i = 0; i < idx; i++) temp += "0";
                for(int i = mul.size(); i < temp.size() ; i++) mul = "0" + mul;
                carry = 0;
                for(int i = temp.size()-1; i >= 0; i--){
                    t = (temp[i] -'0') + (mul[i]-'0') + carry;
                    carry = t/10;
                    t %= 10;
                    char ts = '0' + t;
                    mul[i] = ts;
                }
                if(carry > 0){
                    char cs = '0' + carry;
                    mul = cs + mul;
                }
            }
            idx++;
        }
        return mul;
    }
};
