class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        # Iterative way
        Digit2Letter = { '0':" ", '1':"*", '2':"abc", '3':"def", '4':"ghi", '5':"jkl", '6':"mno",'7':"pqrs", '8':"tuv", '9':"wxyz"}
        if not digits : return []      
        Letters = [""]
        for d in digits:
            temp = []
            for l in Digit2Letter[d]:
                for L in Letters:
                    temp.append(L+l)
            Letters = temp
        
        return Letters
