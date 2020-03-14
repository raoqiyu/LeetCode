class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        
        if n == 0:
            return []
        elif n == 1:
            return [nums]
        
        ret = []
        for i in range(n):
            nums_tmp = nums[0:i] + nums[i+1:]
            for tmp_ret in self.permute(nums_tmp):
                ret.append(tmp_ret+ [nums[i]])
        
        return ret
