class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n == 1:
            return x
        if n < 0:
            x = 1/x
            n = -n
        
        res = self.myPow(x, n//2)
        
        if n%2 == 0:
            res = res*res
        else:
            res = res*x*res
        
        return res
