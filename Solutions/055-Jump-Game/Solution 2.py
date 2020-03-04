class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n_nums = len(nums)
        if n_nums <= 1:
            return True
        if nums[0] == 0:
            return False
        
        # steps we can jump
        steps = nums[0]
        if 0+steps >= n_nums-1:
            return True
        
        for i in range(1, n_nums):
            # use one step 
            steps -= 1
            
            # arrive a new positon, if this position's steps greater than steps we has
            # update steps we can jump
            if nums[i] > steps:
                steps = nums[i]
                if i + steps >= n_nums-1:
                    return True
            # break if we cannot jump 
            if steps == 0:
                break
            
        return True if i == n_nums-1 else False
