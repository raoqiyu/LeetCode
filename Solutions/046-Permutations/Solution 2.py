class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = [] 
        def backtracking(nums, permutation):
            # bound
            if not nums:
                ret.append(permutation)
                return
            # branch
            for i in range(len(nums)):
                backtracking(nums[:i]+nums[i+1:], permutation+[nums[i]])
        backtracking(nums, [])
        
        return ret
