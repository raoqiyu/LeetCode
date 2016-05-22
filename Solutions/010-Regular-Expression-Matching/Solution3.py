class Solution(object):
    cache = {}
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        
        # BackTracking with cache
        if (s,p) in self.cache:
            return  self.cache[(s,p)]
            
        # bound
        if not p:
            return not s
        
        # branch 
        if p[-1] == '*':
            # case 1 : * matches 0 of the preceding elements
            if self.isMatch(s, p[:-2]):
                self.cache[(s,p)] = True
                return True
            # case 2: * matches 1 or more of the preceding elements
            # and if s[-1] == p[-2] || p[-1] == '.' is not satisfy, then all elements before it will not statisfy
            if s and (s[-1] == p[-2] or p[-2] == '.') and self.isMatch(s[:-1], p):
                self.cache[(s,p)] = True
                return True
            
        if s and (s[-1] == p[-1] or p[-1] == '.') and self.isMatch(s[:-1], p[:-1]):
            self.cache[(s,p)] = True
            return True
        self.cache[(s,p)] = False
        
        return False
