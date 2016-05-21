class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        """Dynamic Programming
        table[i][j] : match status between p[:i] and s[:j]
        table[0][0] : match status between two empty string, this is always true
        table[1][1] : match status between p[0] and s[0]
        """
        
        # Initialize the table with False
        #table = [[False]*(len(s)+1)]*(len(p)+1)
        table = [[False] * (len(s) + 1) for _ in range(len(p) + 1)]
        
        # Two empty string
        table[0][0] = True
        
        # Corner Case: s is empty, p is not
        #               Since each '*' can eliminate the previous character
        #               table is vectically updated by the one before previous character
        for i in range(2, len(p)+1):
            table[i][0] = table[i-2][0] and (p[i-1] == '*')
            
        for i in range(1, len(p)+1):
            for j in range(1, len(s)+1):
                if p[i-1] != '*':
                    table[i][j] = table[i-1][j-1] and ( p[i-1] == s[j-1] or p[i-1] == '.')
                else:
                    # Elimilation
                    # '*' matches              0  or 1      of  prevoius character
                    #   s :  abcefg
                    #   p :   d*
                    table[i][j] = table[i-2][j] or table[i-1][j]
                    # Propagation
                    # '*' matches more than 1 of the prevoius character
                    # if p[i-2] == s[i-1], then  * can propagation
                    #  s : abccdef
                    #  p :   c*
                    if p[i-2] == s[j-1] or p[i-2] == '.':
                        table[i][j] |= table[i][j-1]
        return table[-1][-1]
