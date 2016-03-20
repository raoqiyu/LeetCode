class Solution {
public:
    int jump(vector<int>& nums)
    {
        // Greedy
        // start from nums[0], go as long as you can at each jump
        // the lenght you can jump at position i is  k + nums[i + k]for all k that  0 <= k <= nums[i]
        //          firstly, yo can jump with size of k, then at i+k you can jump with size of num[i+k] at most
        // Means that: at position i .e.g,
        //          maximum jump size = j ,  j + nums[i + j] >= k + nums[i + k]
        int len = nums.size();
        if(len < 2)
            return 0;
            
        int startPos = 0;
        int nJump = 1;
        while(true){
            if( startPos + nums[startPos] >= len-1)
                return nJump;
            
            // Search the maximum size you can jump and record the position you can reach
            int maxSize = 0, nextPos;
            for(int size = 0; size<= nums[startPos]; size++){
                if(size + nums[startPos + size] > maxSize){
                    maxSize = size + nums[startPos + size];
                    nextPos = startPos + size;
                }
            }
            startPos = nextPos;
            nJump++;
        }
    }

};
