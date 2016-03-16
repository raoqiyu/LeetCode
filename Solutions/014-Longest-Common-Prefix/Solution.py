class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        endIdx = -1
        GO = 1
        if not strs: return ''
        while GO:
            endIdx += 1
            
            val = strs[0][endIdx] if endIdx < len(strs[0]) else "END"
            GO = all([val == s[endIdx]  if len(s) > endIdx else False for s in strs])
        return strs[0][:endIdx]
