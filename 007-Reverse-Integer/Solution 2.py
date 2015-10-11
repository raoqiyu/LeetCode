class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        (sign, x)  = (1, x) if x >= 0 else (-1, abs(x))
        ret = 0
        while x != 0 :
            # In python, the negative int's % operator is different from C/C++
            ret = ret * 10 + x % 10
            x = x // 10
        ret *= sign
        return 0 if ret > 2147483647 or ret < -2147483648 else ret
