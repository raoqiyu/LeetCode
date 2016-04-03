class Solution {
public:
    int climbStairs(int n) {
        // Dynamic Programming
        // Steps[i] : number of distinct ways to climb to the top
        // Steps[0] = 1
        // Steps[1] = 2;
        // Steps[i] = Steps[i-2] + Stes[i-1]
        int *Steps = new int[n];
        Steps[0] = 1;
        Steps[1] = 2;
        for(int i = 2; i < n; i++)
            Steps[i] = Steps[i-1] + Steps[i-2];
            
        return Steps[n-1];
    }
};
