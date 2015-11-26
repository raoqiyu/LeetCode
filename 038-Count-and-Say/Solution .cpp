class Solution {
public:
    string countAndSay(int n) {
        if( n <= 0 ) return "";
        string say = "1";
        
        for(int i = 1; i < n; i++)
            say = countAndSay_updated(say);
            
        return say;
        
    }
private:
    string countAndSay_updated(string say_old)
    {
        stringstream say_new;
        int cnt = 0; char last = say_old[0];
        for(int i = 0; i <= say_old.size(); i++){
            if(say_old[i] == last)
                cnt++;
            else{
                say_new << cnt << last;
                cnt = 1;
                last = say_old[i];
            }
        }
        return say_new.str();
    }
};
