class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_p = -float('inf')
        tmp_max,tmp_min = 1,1
        for num in nums:
            tmp_max_num = tmp_max*num
            tmp_min_num = tmp_min*num
            tmp_max = max(tmp_max_num,num,tmp_min_num)
            tmp_min = min(tmp_max_num,num,tmp_min_num)
            max_p = max(max_p,tmp_max)
        return max_p
