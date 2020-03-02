class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = set()
        n = len(nums)
        for i in range(n):
            if i>0 and nums[i]==nums[i-1]:
                continue
            index = n-1
            for j in range(i+1,n):
                a, b = nums[i], nums[j]
                c = 0 - a - b
                if c<b:
                    break
                while nums[index]>c and index>j+1:
                    index = index - 1
                if nums[index]==c and index>j:
                    ans.add((a,b,c))
        return list(ans)
