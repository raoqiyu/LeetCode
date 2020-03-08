class Solution:
    def trailingZeroes(self, n: int) -> int:
        """
        ***000
        trailing zeros: one trailing zero means a 10, 10 = 2*5
        
        how many trailing zeros means how many 2*5, the count of 2 is greater than the count of 5
        
        so calculate the count of 5
        5 : 5
        10: 5 10
        15: 5 10 15
        20: 5 10 15 20
        25: 5 10 15 20 25(5*5, two 5)
        30: 5 10 15 20 25(two 5) 30
        
        trailing zeroes in n! = 
              = n//5 + n//25 + n//125 + ....

        """
        
        cnt = 0
        i = 5
        while i <= n:
            cnt += n//i
            i *= 5

        return cnt
