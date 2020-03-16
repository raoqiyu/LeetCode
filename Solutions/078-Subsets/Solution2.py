class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ret = []
        n = len(nums)
        if n == 0:
            return [[]]
        if n == 1:
            return [[],nums]
        
        for i in range(2<<(n-1), 2<<n):
            bit_masks = bin(i)[3:]
            
            ret.append([nums[j] for j in range(n) if bit_masks[j]=='1'])
        
        return ret
