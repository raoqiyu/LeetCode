class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Optimization : use only O(k) extra space?
        vector<int> ret;
        if(rowIndex < 0) return ret;
        ret.push_back(1);
        if(rowIndex == 0) return ret;
        ret.push_back(1);
        
        for(int i = 2; i <= rowIndex; i++){
            for(int j = 1; j < i; j++)
                ret[j] = ret[j]+ret[j-1];
            ret.push_back(1);

        }
        
        return ret;
    }
};
