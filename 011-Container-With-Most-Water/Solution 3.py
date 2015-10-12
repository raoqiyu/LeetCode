class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        maxVal= 0
        # Use two pointer: head pointer and tail pointer
        i = 0;j = len(height)-1
        while i != j:
            currVal = j-i
            if height[i] < height[j]:
                currVal, i, j = currVal * height[i], i+1, j 
            else :
                currVal, i, j = currVal * height[j], i, j-1 
            maxVal = currVal if currVal > maxVal else maxVal
        return maxVal;
        
