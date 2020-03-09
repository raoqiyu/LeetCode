class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        """
        nums[i] > nums[i+1] or nums[i] < nums[j+1]
        
        nums[0] < nums[1] < ... nums[i] > nums[i+1] > nums[i+2] >....< nums[j] < ...
        nums[0] < nums[1] < ... nums[i] > nums[i+1] > nums[i+2] >....> nums[j] > ...
        
        """
        begin ,end = 0, len(nums)-1
        
        while begin < end:
            mid = (begin+end)//2
            if nums[mid] < nums[mid+1]:
                begin = mid + 1
            else:
                end = mid
        
        return begin
