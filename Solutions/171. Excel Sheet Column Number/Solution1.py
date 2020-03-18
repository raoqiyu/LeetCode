class Solution:
    def titleToNumber(self, s: str) -> int:
        """
        A = 1
        Z = 26
        """
        if s == '':
            return 0
        base = ord('A')-1
        num, multipy = 0, 1
        for c in s:
            num = num*26 + (ord(c) - base)
        
        return num
