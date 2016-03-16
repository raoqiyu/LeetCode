class Solution {
private:
    vector<string> ret;
    int nPair;
public:
    vector<string> generateParenthesis(int n) {
        // Backtracking Solution
        nPair = n;
        generate(0, 0, "");
        return ret;
    }
    
    
    void generate(int lidx, int ridx, string s)
    {
        // lidx : number of "(" we have used
        // ridx : number of ")" we have used
        
        // If we use all ")", this means we also use all the "(", reutrn 
        if( ridx == nPair){
            ret.push_back(s);
            return;
        }
        
        // If we still have availab "(" , use it 
        if( lidx < nPair)
            generate(lidx+1, ridx, s+"(");
        // If ridx < lidx, this means we can use a ")" at this position 
        if( ridx < lidx)
            generate(lidx, ridx+1, s+")");
            
        return ;
    }
};
