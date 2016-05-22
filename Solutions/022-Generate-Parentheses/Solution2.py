class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ret = []
        def dfs(lidx, ridx, s, n):
            # if all pairs used, return 
            if ridx == n:
                ret.append(s)
                return 
            # else, start using a new pair
            if lidx < n:
                dfs(lidx+1, ridx, s+'(', n)
            # if there is a pair is not closed, closing it.
            if ridx < lidx:
                dfs(lidx, ridx+1, s+')', n)
        
        dfs(0, 0, '', n)
        
        return ret
