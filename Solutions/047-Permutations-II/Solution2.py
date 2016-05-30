class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = [] 
        nums.sort()
        def backtracking(nums, permutation):
            # bound
            if not nums:
                ret.append(permutation)
                return
            # branch
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i-1]:
                    continue
                backtracking(nums[:i]+nums[i+1:], permutation+[nums[i]])
        backtracking(nums, [])
        
        return ret
