class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        """
        0	 	 	 	8	 	 	 	16	 	 	 
        1	 	 	7	9	 	 	15	17	 	 	 
        2	 	6	 	10	 	14	 	18	 	 	 
        3	5	 	 	11	13	 	 	19	 	 	 
        4	 	 	 	12	 	 	 	20	 	 	 
        """
        if numRows == 1:
            return s
        index = 0
        lines = ['' for i in range(numRows)]
        # Repeat:
        #       iterate numRows times from up to bottom
        #       iterate numRows - 2 times in Diagonal direction 
        while index < len(s):
            for j in range(numRows):
                lines[j] += s[index]
                index += 1
                if index == len(s):
                    return ''.join(lines)
            for j in range(numRows-2,0,-1):
                lines[j] += s[index]
                index += 1
                if index == len(s):
                    return ''.join(lines)
