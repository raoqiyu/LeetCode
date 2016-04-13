class Solution {
public:
    vector<int> grayCode(int n) {
        // add a high bit with value 1
        // n = 0    0
        // n = 1    0   1
        // n = 2   00  01  11  10
        // n = 3  000 001 011 010 110 111 101 100
        vector<int> ret;
        ret.push_back(0);
        int highBit = 0;
        while(n--){
            highBit = ret.size();
            for(int i = ret.size() -1; i >= 0; i--)
                ret.push_back(highBit|ret[i]);
        }
        return ret;
    }
};
