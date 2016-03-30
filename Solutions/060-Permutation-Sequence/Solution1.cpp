class Solution {
public:
    string getPermutation(int n, int k) {
        
        // Consider the element at the first position in a permutation
        // 1 exists in the first  (n-1)! permutations   1 2 3; 1 3 2;
        // 2 exists in the second (n-1)! permutations   2 1 3; 2 3 1;
        // 3 exists in the thrid  (n-1)! permutations   3 1 2; 3 2 1;
        //.....
        // n exists in the n-th   (n-1)! permutations   n 1 2 3 ... n-1; ..; n n-1 .. 3 2 1;
        // 
        // The element at the second has the same situation
        // .....
        
        string s = "";
        int factor[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        for(int i = 1; i <= n; i++)   s += i+'0';
        if(k-- == 1) return s;
        
        string ret="";
        int nPermutation;
        for(int i = 1; i <= n; i++){
            nPermutation = factor[n-i];
            // the i-th character in this permutation is the k/(n-i)! element in s
            // because each (n-1)! permutations have same character at position i
            int selected = k / nPermutation;
            // Once we have determine the character at positon i, we select one permutation in the (n-i)! permutaions
            // the character at position i+1 is the element in that selected permutation, 
            // so we update k to locate at the permutation we selected
            k %= nPermutation;
            
            ret += s[selected];
            s.erase(s.begin()+selected);

        }

        return ret;
    }
};
