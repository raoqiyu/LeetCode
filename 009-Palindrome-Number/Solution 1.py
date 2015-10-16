class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        for i in range(len(str(x))//2):
            if str(x)[i] != str(x)[len(str(x))-i-1]:
                return False
        return True
