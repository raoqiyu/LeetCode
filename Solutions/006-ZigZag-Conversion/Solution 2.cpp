class Solution {
public:
    string convert(string s, int numRows) {
        /*
        0	 	 	 	8	 	 	 	16	 	 	 
        1	 	 	7	9	 	 	15	17	 	 	 
        2	 	6	 	10	 	14	 	18	 	 	 
        3	5	 	 	11	13	 	 	19	 	 	 
        4	 	 	 	12	 	 	 	20	 	 	 
        */
        /*
        P   A   H   N
        A P L S I I G
        Y   I   R
        
        in ZigZag format, the Iteration period foreach line is 2*numRows - 2 about to the origin format
        */
        if (numRows == 1)
            return s;
        int index = 0, length = s.size();
        string ret = "";
        // Repeat:
        //       Iteration period is 2*numRows - 2 for each line
        //       cosider the lines between head an tail lines
        int period = 2*numRows - 2;
        for(int i = 0; i < numRows; i++)
            for(int j = i; j < length; j+=period){
                ret += s[j];
                if (i > 0 && i < numRows-1) {  
                    int k = j + period - 2*i;  
                    if (k < length)
                        ret += s[k];  
                }
            }
        
        return ret;
        
    }
};
