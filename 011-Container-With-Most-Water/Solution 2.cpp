class Solution {
public:
    int maxArea(vector<int>& height) {
        auto start = height.begin();
        auto end = height.end() - 1;
        int maxVal = 0, currVal = 0;
        while(start != end){
            currVal = (int)(end - start);
            if(*start < *end){
                currVal *= *start;
                start++;
            }else{
                currVal *= *end;
                end--;
            }
            maxVal = max(maxVal, currVal);
        }
        return maxVal;
    }
};
