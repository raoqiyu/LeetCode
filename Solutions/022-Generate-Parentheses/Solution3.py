class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n < 1:
            return []
        
        self.ret = []
        self.kernel(n,n,'')
        
        return self.ret
    
    def kernel(self, left ,right, comb):
        if left > right:
            return
        if left == right == 0:
            self.ret.append(comb)
            return
        
        if left > 0:
            self.kernel(left-1, right, comb+'(')
        if right > 0:
            self.kernel(left, right-1, comb+')')
