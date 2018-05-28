class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret = {0,0};
        int begin=0, end=numbers.size()-1, tmpSum = 0;
        while(begin < end){
            tmpSum = numbers[begin]+numbers[end];
            if(tmpSum < target)
                begin = binarySearch(numbers, begin+1, end-1, target-numbers[end]);
            else if (tmpSum > target)
                end = binarySearch(numbers, begin+1, end-1, target-numbers[begin]);
            else
                break;
        }
    
        return vector<int>{begin+1,end+1};
    }
    
    int binarySearch(vector<int>& numbers, int low, int high, int target){
        int m = 0;
        while(low < high){
            m = (low+high)/2;
            if(numbers[m] == target)
                return m;
            else if(numbers[m] < target)
                low = m + 1;
            else
                high = m-1;
        }
        
        return low;
    }
};
