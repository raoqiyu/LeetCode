class Solution {
public:
    int numTrees(int n) {
        // Dynamic Programming
        // number of root's BST = # of left * # of right
        // nums[i] : the number of unique BST's with 1..i
        // when calculate nums[i] : take i as node, then 1..j as left j..i-1 as right , for j = 1 to i-1
        vector<int> nums;
        nums.push_back(1);
        
        for(int i = 1; i <= n; i++){
            nums.push_back(0);
            for(int j = 0; j < i; j++){
                nums[i] += nums[j] * nums[i-j-1];
            }
        }
        return nums[n];
    }
};
