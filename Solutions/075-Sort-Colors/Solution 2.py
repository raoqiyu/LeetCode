class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n_nums = len(nums)
        
        # nums[:ptr0] is 0
        # nums[ptr1:ptr2] is 1
        # nums[ptr2:] is 2
        ptr0, ptr1, ptr2 = 0, 0, n_nums-1
        while ptr0 < n_nums and nums[ptr0] == 0:
            ptr0 += 1
        
        ptr1 = ptr0
        while ptr1 < n_nums and nums[ptr1] == 1:
            ptr1 += 1
        
        while ptr2 > 0 and nums[ptr2] == 2:
            ptr2 -= 1
        
        while ptr1 <= ptr2:
            if nums[ptr1] == 0:
                nums[ptr0], nums[ptr1] = nums[ptr1], nums[ptr0]
                ptr0 += 1
                ptr1 += 1
            elif nums[ptr1] == 1:
                ptr1 += 1
            else:
                nums[ptr1], nums[ptr2] = nums[ptr2], nums[ptr1]
                ptr2 -= 1
        
