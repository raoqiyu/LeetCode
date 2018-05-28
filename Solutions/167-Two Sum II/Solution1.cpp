class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret = {0,0};
        int begin=0, end=numbers.size()-1, tmpSum = 0;
        while(begin < end){
            tmpSum = numbers[begin]+numbers[end];
            if(tmpSum < target)
                begin++;
            else if (tmpSum > target)
                end--;
            else
                break;
        }
        if(begin < end){
            ret[0]=begin+1;
            ret[1]=end+1;   
        }
    
        return ret;
    }
};
