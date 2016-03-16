class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # char_visited : store visited char and its newest index
        # longest  : return value
        # start  : the start index of current substring
        char_visited , longest, start = {}, 0, 0
        
        # <index, character> 
        for i, ch in enumerate(s):
            # If ch already exists in s
            if ch in char_visited:
                # Two cases
                # Case 1: the last ch is not in the current substring
                # Case 2: the last ch is in the current substring
                # So, we should update the start index of the substring aacrroding to the given case
                start = max(start, char_visited[ch]+1)
            longest = max(longest, i - start+1)
            # Update ch's index to make sure it keep the newest index
            char_visited[ch] = i
        return longest
