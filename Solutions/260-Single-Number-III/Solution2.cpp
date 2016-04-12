class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Bit Manipulation
        // Split A and b into two defferent sequence, (there have different bit info)
        // And afetr we splited the array, the same number which appear exactly twice will in the same sub-array
        // when we do xor operation, they will be zero
        int AxorB = 0;
        for(auto n : nums)
            AxorB ^= n;
            
        int mask = AxorB & (~(AxorB-1));
        int A = 0, B = 0;
        
        for(auto n : nums){
            if(n & mask){
                A ^= n;
            }else
                B ^= n;
        }
        
        return vector<int>{A,B};
    }
};
