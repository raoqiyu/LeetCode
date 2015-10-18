class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        Roman   = [ 'M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I', '']
        Integer = [1000,  900, 500,  400, 100,   90,  50,   40,  10,    9,   5,    4,   1,  0]
        ret  = ''
        for i in range(len(Integer)-1):
            ret += Roman[i] * (num//Integer[i])
            num %= Integer[i]
        return ret
