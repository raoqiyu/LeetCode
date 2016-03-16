class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        length = len(nums)
        ret = []
        for k in range(length - 2):
            i, j = k+1, length-1
            while i != j:
                val = nums[k] + nums[i] + nums[j] 
                if val == 0 and [nums[k],nums[i],nums[j]] not in ret:
                    ret.append([nums[k],nums[i],nums[j]])
                if val < 0:
                    i += 1
                else:
                    j -= 1
        return ret
