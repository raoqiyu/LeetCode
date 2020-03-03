class Solution:
    digit2letter = {2:['a','b','c'],3:['d','e','f'],4:['g','h','i'],
                        5:['j','k','l'],6:['m','n','o'],7:['p','q','r','s'],
                        8:['t','u','v'],9:['w','x','y','z']}
        
    def letterCombinations(self, digits: str) -> List[str]:
        ret = []
        if not digits:
            return ret

        tmp = self.letterCombinations(digits[1:])            
        for letter in self.digit2letter[int(digits[0])]:
            if tmp:
                for s in tmp:
                    ret.append(letter+s)
            else:
                ret.append(letter)
        
        return ret
