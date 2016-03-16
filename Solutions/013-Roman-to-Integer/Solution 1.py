class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        mappedDict = {'I' : 1, 'V' : 5, 'X' : 10, 'L' : 50, 'C' : 100, 'D' : 500, 'M' :1000}
        ret = mappedDict[s[-1]]
        for index in range(len(s) - 1):
            ret += mappedDict[s[index]] if mappedDict[s[index]] >= mappedDict[s[index+1]] else -mappedDict[s[index]]
        return ret
