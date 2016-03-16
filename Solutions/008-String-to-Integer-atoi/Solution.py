class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        # Discard whitespace
        str = str.lstrip()
        # Discard all in valid subsequence
        for i, s in enumerate(str):
            if s not in '-+' and not s.isdigit():
                str = str[:i]
                break;
        # Check  -+ -- ++ +-
        try:
            ret = int(str)
        except:
            return 0
        return max(min(ret,2147483647),-2147483648)
