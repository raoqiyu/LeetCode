class Solution {
public:
    string intToRoman(int num) {
        vector<string>   Roman =  {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int>    Integer =  {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string RomanNum  = "";
        for(int i = 0; i < 13; i++){
            for(int k = num/Integer[i]; k > 0; k--)
                RomanNum.append(Roman[i]);
            num %= Integer[i];
        }
        return RomanNum;
    }
};
