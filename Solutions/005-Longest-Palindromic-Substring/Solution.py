class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Manacher’s ALGORITHM
        # https://en.wikipedia.org/wiki/Longest_palindromic_substring
        
        # s2: a derived string of s, comprising N * 2 + 1 elements
        # Here in python implementation, N*2 + 1 +2 to avoid the s2[N*2+1+1] check
        s2 = '$#' + '#'.join(s) + '#_'
        # p : an array of palindromic span for each element in s2, from center
        #     to either outermost element, where each element is counted towards
        #     the length of a palindrome
        # To avoid calculate, use max value
        p = [0] * 4003
        # c : the position of the center of the palindrome currently known to 
        #     inlude a boundary closest to the right of s2
        #     length of palindrome = p[c]*2+1
        # r : the position of the right-most boundary of current palindrome
        #     r = c + p[c]
        # i : the position of an element
        # j : the mirrored position of i around c
        #     j = 2 * c -i
        # mc mp : the center and span of the palindrome which has the max span
        #         currently
        c, r, mc, mp = 0, 0, 0, 0
        for i in range(1, len(s2) - 1):
            if r > i:
                # i is in the current palindrome that has max length(centered at c)
                # so the mirrored position of i can provide information
                # to determine the current palindrome length(centered at i)
                # Two case
                # Notation: p_j, the palindrome certered at j
                #           p_i, the palindrome certered at i
                #           p_c, the palindrome certered at c
                j = 2 * c -i
                if r - i > p[j]:
                    # Case 1: p_j is within p_c
                    # in this case, length of p_i is ad least p[j]
                    p[i] = p[j]
                else:
                     # Case 2: p_j is not within p_c
                     # in this case, to find the length of p_i, the right-most character of p_c should be compared with its mirror character about the center of i
                     # so the length of p_i is at least r - i
                    p[i] = r - i
            else:
                # i is not in the current palindrome that has max length(centerd at c)
                # so the mirrored position of i can not provide information
                p[i] = 1
            # Update p[i]
            while s2[i + p[i]] == s2[i - p[i]]:
                p[i] += 1
            # Update c and r
            if i + p[i] > r:
                r = i + p[i]
                c = i
            # Update mc and mp
            if mp < p[i]:
                mp = p[i]
                mc = i
        return s[mc//2 - mp//2: mc//2 - mp//2 + mp - 1]
