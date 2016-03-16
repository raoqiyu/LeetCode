class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mappedDict = { {'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        int num = mappedDict[s[0]];
        for(int i = 1; i < s.size(); i++){
            num += mappedDict[s[i]];
            if(mappedDict[s[i]] > mappedDict[s[i-1]])
                num -= 2*mappedDict[s[i-1]];
        }
        return num;
    }
};
