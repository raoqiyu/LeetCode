class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        mappedDict = {'I' : 1, 'V' : 5, 'X' : 10, 'L' : 50, 'C' : 100, 'D' : 500, 'M' :1000}
        mappedS = [mappedDict[x] for x in s]
        ret = mappedDict[s[-1]]
        for index in range(len(mappedS) - 1):
            ret += mappedS[index] if mappedS[index] >= mappedS[index+1] else -mappedS[index]
        return ret
