class Solution {
public:
    vector<int> grayCode(int n) {
        // Mathematic solution
        // the i-th gray code is (i>>1)^i
        // gray   code : 000 001 011 010 110 111 101 100
        // binary code : 000 001 010 011 100 101 110 111
        // binary >> 1 : 000 000 001 001 010 010 011 011
        vector<int> ret;
        for(int i = 0; i < (1<<n); i++)
            ret.push_back( i^(i>>1) );
        return ret;
    }
};
