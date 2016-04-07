class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        ret.clear();
        N = n;
        K = k;
        vector<int> temp;
        comb(1,temp);
        
        return ret;
    }

private:
    vector<vector<int>> ret;
    int N, K;
    void comb(int i, vector<int>& temp){
        if(temp.size() == K){
            ret.push_back(temp);
            return;
        }
        
        if(i <= N){
            //with j
            temp.push_back(i);
            comb(i+1, temp);
            temp.pop_back();
            // without j
            comb(i+1, temp);
        }
    }
};
