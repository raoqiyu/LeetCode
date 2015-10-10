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
        if (numRows == 1)
            return s;
        int index = 0, length = s.size(),zigNum = numRows-2;
        string lines[numRows] = {""};
        // Repeat:
        //       iterate numRows times from up to bottom
        //       iterate numRows - 2 times in Diagonal direction 
        while (index < length){
            for(int j=0; j < numRows && index < length; j++){
                lines[j] += s[index++];
            }
            for(int j = zigNum; j > 0 && index < length; j--){
                lines[j] += s[index++];
            }
        }
        string ret = "";
        for(int j = 0; j < numRows; j++)
            ret += lines[j];
        return ret;
        
    }
};
