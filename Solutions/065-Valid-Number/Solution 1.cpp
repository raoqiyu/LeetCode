class Solution {
public:
    bool isNumber(string s) {
        // strip
        int left = 0, right = s.length()-1;
        while(s[left]  == ' ') left++;
        while(s[right] == ' ') right--;
        if(s[left] == '-' || s[left] == '+') left++;
 
        
        bool num = false, dot=false, e = false, blank=false;
        
        for(int i = left; i <= right; i++){
            char c = s[i];
            if(c == ' '){
                blank = true;
            }else if (blank == true){
                return false;
            }else if(c >= '0' && c <= '9'){
                num = true;
            }else if(c == '.'){
                if(dot == true || e == true){
                    return false;
                }else{
                    dot = true;
                }
            }else if(c == 'e'){
                if(e == true || num == false){
                    return false;
                }else{
                    e = true;
                    num = false;
                    if(s[i+1] == '-' || s[i+1] == '+')
                        i++;
                }
            }else{
                return false;
            }

        }
        return num;
    }
};
