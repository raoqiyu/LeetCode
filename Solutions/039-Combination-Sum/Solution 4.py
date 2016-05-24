class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        # Dynamic Programming
        dp = [ [] for i in range(target+1)]
        dp[0] = [[]]
        
        candidates.sort()
        
        for i in range(1, target+1):
            for num in candidates:
                if num > i:
                    break
                for L in dp[i-num]:
                    if not L or L[-1] <= num:
                        dp[i] += [L + [num]]
                        
        return dp[target]
        
