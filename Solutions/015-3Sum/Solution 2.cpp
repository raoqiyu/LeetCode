class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        length = len(nums)
        ret = []
        for k in range(length - 2):
            # Avoid doing same operations in the while loop
            if (k > 0) and (nums[k-1] == nums[k]) : continue
            i, j = k+1, length-1
            while i < j:
                val = nums[k] + nums[i] + nums[j] 
                if val == 0:
                    ret.append([nums[k],nums[i],nums[j]])
                    i += 1; j -= 1;
                    # avoid check on same number
                    while i < j :
                        if nums[i-1] == nums[i]:
                            i += 1
                        elif nums[j+1] == nums[j]:
                            j -= 1
                        else:
                            break
                elif val < 0:
                    i += 1
                else:
                    j -= 1
        return ret
