class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        (sign, num) = ('',str(x)) if x > 0 else ('-', str(abs(x)))
        ret = int(sign+num[::-1])
        return 0 if ret > 2147483647 or ret < -2147483648 else ret
        
