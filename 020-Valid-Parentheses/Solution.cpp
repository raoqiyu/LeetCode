class Solution {
public:
    bool isValid(string s) {
        vector<char> Pare;
        map<char, char> PareDict{{'(', ')'}, {'[', ']'}, {'{', '}'}};
        
        for(auto c : s){
            if( c == '(' || c == '[' || c == '{' ){
                Pare.push_back(c);
            }else if( c == ')' || c == ']' || c == '}' ){
                if( Pare.size() > 0 && c == PareDict[Pare[Pare.size()-1]])
                    Pare.pop_back();
                else
                    return false;
            }
        }
        
        if( Pare.size() == 0) return true;
        return false;
    }
};
