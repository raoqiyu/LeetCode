class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows <= 0) return ret;
        
        ret.push_back(vector<int>{1});
        vector<int> tmp;
        
        for(int i = 2; i <= numRows; i++){
            tmp.clear();    
            tmp.push_back(1);
            for(int j = 0; j < i-2; j++)
                tmp.push_back(ret[i-2][j]+ret[i-2][j+1]);
            tmp.push_back(1);
            ret.push_back(tmp);
        }
        
        return ret;
    }
};
