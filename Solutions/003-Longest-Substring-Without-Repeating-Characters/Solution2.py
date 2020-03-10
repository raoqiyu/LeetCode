class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        if n <= 1 :
            return n
        begin, length = 0, 1
        char2pos = {s[0]:0}
        for i in range(1, n):
            if char2pos.get(s[i], -1) >= begin:
                # only record length when find a repeating char
                length = max(length, i - begin)
                begin = char2pos[s[i]]+1
            char2pos[s[i]] = i
            
        length = max(length, i - begin+1)
        return length
