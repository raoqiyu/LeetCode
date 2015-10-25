class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        # BackTracking way
        Digit2Letter = { '0':" ", '1':"*", '2':"abc", '3':"def", '4':"ghi", '5':"jkl", '6':"mno",'7':"pqrs", '8':"tuv", '9':"wxyz"}
        if not digits : return []      
        Letters = []
        def Combinations(digits, index, s):
            if index == len(digits):
                Letters.append(s)
                return
            for i in Digit2Letter[digits[index]]:
                Combinations(digits, index+1, s+i)
            return 
        
        Combinations(digits, 0, '')
        return Letters
