class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # {num:index,...}
        hashMap = dict(zip(nums,range(len(nums))))
        for i in range(len(nums)):
            if target-nums[i] in hashMap and i < hashMap[target-nums[i]]:
                return [i+1, hashMap[target-nums[i]]+1]
