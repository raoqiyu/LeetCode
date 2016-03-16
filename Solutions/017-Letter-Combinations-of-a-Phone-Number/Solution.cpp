class Solution {
private: 
    map<char,string> Digit2Letter = { {'0', ""}, {'1',""}, {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},
                                            {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};
    vector<string> Letters;
    void Combinations(string digits, string letters)
    {
        // If at the end of digits, return 
        if( digits.size() == 0){
            if( letters.size() != 0) Letters.push_back(letters);
            return ;
        }
        
        // Check each possible conbination ( each letter in Digit2Letter[digits[0]])
        for(int i = 0; i < Digit2Letter[digits[0]].size(); i++){
            Combinations(digits.substr(1), letters+Digit2Letter[digits[0]][i]);
        }
        
    }
    
public:
    vector<string> letterCombinations(string digits) {
        Combinations(digits, "");
        return Letters;
    }
};
