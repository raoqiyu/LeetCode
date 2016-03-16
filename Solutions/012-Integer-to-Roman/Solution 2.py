class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        Roman   = [ 'M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        Integer = [1000,  900, 500,  400, 100,   90,  50,   40,  10,    9,   5,    4,   1]
        ret  = ''
        for i,v in enumerate(Integer):
            ret += Roman[i] * (num//v)
            num %= v
        return ret
