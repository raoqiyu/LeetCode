class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        # This solution is a rigged one， but it is very fast because of python's feature
        # In python, use native function is good choice
        ret_nums = nums1 + nums2
        ret_nums.sort()
        return (ret_nums[(len(ret_nums)-1)//2] + ret_nums[len(ret_nums)//2]) / 2.0
